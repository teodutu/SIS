# Extraction
The only decent challenge (because it's not web-based...).

`nm` shows that variable `flag` is at address `0x4009a0`, which is inside the `.rodata` section.
Upon inspection using `xxd`, the string `SIS_CTF{aaaaaaaaaaaaaaaaaaaaaaaaaa}` is stored at this address (inside the "public" binary).

As a result, I crafted a shellcode that `write`s 35 bytes (the length of the flag) from address `0x4009a0` to `stdout`.
And this was it.
