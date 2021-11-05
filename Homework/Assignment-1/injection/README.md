# Injection
Definetly the coolest challenge.
What a surprise: all good challenges are binary exploits...

Anyways, passive-aggressiveness aside, the binary is obviously vulnerable: it `fread`s 64 bytes into a 32-byte stack buffer.
So it's shellcode-able.
There's one issue, however: ASLR is most likely on remotely.
I didn't try to find out though, because I bypassed it completely!

The data sections (`.data` + `.bss` + `.rodata` etc) are also write-executable, which means that the shellcode can be written to and exectuted from there.
These sections are mapped as a page starting from address `0x8049000`.
I'll just call this page "the data page" from now.
Time for a 2-stage attack!


## First Stage: Pivoting the Stack
In order to move the stack to the data page, I had to overwrite the saved `ebp`, at offset `32 + 4 = 36` from the beginning of the buffer, and then overwrite the saved `eip` to recall `main`.
But the second time I called it, I skipped its preamble so `ebp` would stay where I placed it after the first stage.
Also, the overwritten `ebp` is not `0x8049000`, but `0x8049020` because `fgets` reads bytes to `[ebp - 0x20]` and going below thes data page would result in a seg fault.


## Second Stage: The Shell
Now, with the stack placed onto the aforementioned data page, I used [this](https://packetstormsecurity.com/files/154870/Linux-x86-execve-bin-sh-Shellcode.html) shellcode and overwrote `main`'s saved `eip` with `0x8049000` (the beginning of the shellcode).
And that was it.
