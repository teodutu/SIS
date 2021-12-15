# Classic
This challenge is pretty obvious.
It truly is a classic.

The binary reads an input of 127 bytes into a 48-byte stack buffer.
This means that it's vulnerable to an overflow attack.
For this, I used 2 stages.

## Stage 1 - Leaking the adress of `puts`
The first stage leaks the libc address of `puts` by calling `puts@plt(puts@got)` via a ROP chain.
At the end of this ROP chain, I put the address of `main` in order to re-call the function and send it the second stage payload.

## Stage 2 - Calling `system("/bin/sh")`
With the help of the aforementioned leak, I computed the address where libc is mapped by subtracting the offset of `puts` in libc form the address provided by the leak.
The address of the `system` function is, thus, `libc_address + system_offset_in_libc`.
The parameter (`"/bin/sh"`) exists as a string inside libc, so I had everything I needed.
The second stage payload essentially calls `system("bin/sh")`, using their addresses from libc.
