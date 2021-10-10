# SIS
[Security of Information Systems](http://elf.cs.pub.ro/sis) - UPB 2021-2022



## Labs
### Lab 1 - Introduction
Generic exploration tasks.
One takeaway from [task 4](http://elf.cs.pub.ro/sis/sessions/01-intro-systems-security.html#tasks) was that an often overlooked security mechanism in Linux is called [capabilities](https://man7.org/linux/man-pages/man7/capabilities.7.html).
There are 2 interesting commands:
- `setcap`
- `getcap`


### Lab 2 - Authentication
#### Task 1 - Breaking Hashes
This task showcases a few ways to break `sha256` hashes of passwords:
- dictionary attacks
- brute force
- substitution
- punctuation

But they all rely on some sort of exhaustive search through a list of possible hashes.

On top of these, there is also a bit of social engineering in task `h`.

Task 4 is your typical side-channel attack, whereby a password checking app iterates through it in plaintext and returns as soon at the first incorrect byte.
