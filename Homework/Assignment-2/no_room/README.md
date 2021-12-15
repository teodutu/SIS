# No Room
This challange was really nice.
It's a 2-stage exploit, similar to [Classic](../clasic), but also with pivoting the stack onto the `.data` section, because the vulnerable stack buffer isn't large enough.

The program performs 2 `read`s.
One is of size `0x44` into a stack buffer of length `0x30`.
This one is not sufficient to house either rop chain: neither the one for leaking the address of `puts`, nor the one for getting a shell.
The other `read` is of a larger size (`0x7f`), but the buffer is in the `.data` section.
In order to pop gadgets from this buffer, we have to pivot the stack to overlap with the part of the `.data` section where the second buffer lies.
The first call to `read` uses the data buffer, while the second uses the stack buffer.

## Stage 1 - Pivoting the stack and Leaking the Address of `puts`
The data payload is similar to the one used for [Classic](../clasic) and intends to leak the address of `puts` by calling `puts@plt(puts@got)` and then re-calls `main`.
The extra trick now is the stack payload, which overwrites the saved `rbp` with the address of the data buffer and the return address with the address of a `leave ; ret` gadget.
This gadget is used to make `rsp` also point to the new stack.

## Stage 2 - Calling `system("/bin/sh")`
This step is quite similar to the one performed when expliting [Classic](../clasic).
Check out that challenge's [README.md](../clasic/README.md) for details.
I appended a padding **at the end** of the payload because the binary places a `\0` at the end of the payload and because now the data buffer and the stack buffer don't overlap perfectly.
There's an 8-byte mismatch between them.
