# Extraction
The only decent challenge (because it's not web-based...).

The binary reads a small (at most 32 bytes) shellcode and then runs it, but only if it does not contain the characters `b`, `n`, `i`, `h` or `s`.
So no `/bin/sh` is allowed :(.

However, `nm` shows that a variable called `flag` (wink, wink) is at address `0x4009a0`, which is inside the `.rodata` section.
Upon inspection using `xxd`, the string `SIS_CTF{aaaaaaaaaaaaaaaaaaaaaaaaaa}` is stored at this address (in the "public" binary, that is).

As a result, I crafted a shellcode that `write`s 35 bytes (the length of the flag) from address `0x4009a0` to `stdout`.
And this was it.
