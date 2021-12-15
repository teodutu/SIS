# Flag Debug
The binary wants to receive the flag as a command-line parameter.
It then reads the real flag from `./flag` and calculates the `xor` sum of the 2 flags, like so: `sum += flag[i] ^ argv[1][i]`, for `i in [0..flag.length]`
If this sum 0, then the given flag is most likely correct.
Otherwise, this sum is printed.

Obviusly, the closer the 2 flags are to each other, the lower this sum will be.
This makes the binary vulnerable to a sidechannel attack.
But first, in order to find the length of the flag, we can use `ls -l` to find the file size to be 37 bytes.
Given the flag contains a trailing `\n` character, the length of the flag is 36 bytes.

Now for the exploit.
I made a dummy 36-byte flag: `SIS_CTF{aaa...a}` and then iterated over each `a` and tried replacing it with all possible letters, digits and `_`.
I gave each of these attempted flags to the binary and the correct letter at each position was the one that minimised the sum printed by the binary.

When the flag is correct, the binary `"Congratulations, you found the flag!"`.
Upon receiving this string, the flag is constructed completely.

**Note:** because the user `ctf3` doesn't have write permisions inside the remote `flag_debug` folder, I placed the exploit in `/home/ctf3` and ran it from the Python console like so: `exec(open('../exploit.py').read())`.
