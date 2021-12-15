# Wart
The files inside the archive seem meaningless.
They all contain 128 random bytes.
Upon inspecting the tar archive with `xxd`, I saw that it contains some strings like `user.flag=<letter>`.

More specifically, each file seems to have its own `user.flag=<letter>`.
I assumed each file starts with the "header" `wart/PaxHeaders.5261/`, folowed by the file name (i.e. its number).
So I created a dictionary that maps file numbers to the corresponding letters from `user.flag=<letter>`.

After filling this dictionary, I printed its values in the order given by its keys and that was the flag.
