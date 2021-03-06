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


### Lab 3 - Application Exploit
4 typical SSS beginner-level exploiting tasks. The only rather notable taks is
[task 3.c](./Labs/Lab3/ret-to-libc/exploit.py) where a simple 1-stage
ret-to-libc exploit is performed. Only 1 stage is necessary as ASLR is turned 
off, so the address of `libc` can be found by simply running `ldd`.


### Lab 4 - Web Exploit
A few simple web exploiting tasks, which showcase the usage of:
- [dirb](https://sourceforge.net/projects/dirb/)
- unsanitised user inputs
- sql injection
- query parameter exploitation


### Lab 5 - DEP & ASLR
ASLR is bypassed by ret-to-plt.
DEP is bypased by ret-to-libc.


### Lab 6 - ROP & DOP
The ROP tasks are classics.
The DOP task is bullshit.
The vulnerable program is an interpreter that can be made to print any 6-digit string.
It's all about computing offsets.
Boring.


### Lab 7 - App Confinement
A weird lab about [AppArmor](https://apparmor.net/), `chroot` and `secoomp`.
Not much is of interest.


### Lab 8 - System Isolation
Cracking `chroot`, VMs and other bullshit.
Uninteresting.


### Lab 9 - Code Analysis
This lab has us investigate a bunch of code bases in order to discover bugs.
Some static analysis tools like `cppcheck`, `flawfinder` and `clang-tidy` are also explored.



## Homework
### Assignment 1
Some rather boring challenges.
The most interesting of them is [`injection`](Homework/Assignment-1/injection).
It can be solved in a simpler way, but I chose to pivot the stack in order to make room for the shellcode.


### Assignment 2
Some more annoying misc and forensics challenges.
The more interesting one is probably [`no_room`](./Homework/Assignment/no_room).
The reason it's interesting is because it requires pivoting the stack onto the `.data` section because the stack buffer is not large enough.
