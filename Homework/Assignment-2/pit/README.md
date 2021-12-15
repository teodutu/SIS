# Pit
I figured out this one after doing [Wart](../wart) as both of them were solved by looking at the files' metadata.
By concatenating all 3 parts and then "untaring" the resulting archive, a directory is created.
This directoy contains 36 files (except for the .gitignore).
36 looks like the average flag length, so it's likely that each file corresponds to 1 letter.

Running `stat` on various files, I saw that their number of blocks was different.
Moreover, these numbers were all divisible by 8 and performing this division brought each number inside the ASCII range.
So I obtained the flag by concatenating the characters corresponding to the ASCII codes given by dividing the number of blocks of each file (after sorting them numerically by name) by 8.
The wrapper script that performs all operations is `exploit.sh`.
