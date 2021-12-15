# Tic Toc
The binary reads 4 bytes from `/dev/urandom` into an `int` variable.
This variable is then written to a file with a random name starting with `tmp`.
Then, the program sleeps for a few microseconds before reading the random variable from the `tmp*` file.
This newly read number is then compared with the parameter given to the process from the CLI.
If they're the same, the binary reads the flag from `./flag` and prints it.

Because the program sleeps between writing the number to `tmp*` and reading it, this file can be "poisoned" by writing anything to it.
The exploit writes 4 bytes of `\x00` to all `tmp*` files, so that when the binary reads the number for the second time, it reads 0.

The exploit has to be run in the background, from `/home/ctf4`, while the binary has to be run afterwards, like so: `./tictoc 0`.
