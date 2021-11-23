# Paranoia
This one is the weirderst challenge I swear...

So running `ls -l` I saw the `+` sign next to the permissions of the flag, which meant it had some sort of ACL set:
```
ctf@rd-ixiachallenge-18:~$ ls -l
total 4
-r--------+ 1 root root 33 Nov  5 17:39 flag
```
I then used `getfacl` to find this ACL:
```
ctf@rd-ixiachallenge-18:~$ getfacl flag
# file: flag
# owner: root
# group: root
user::r--
user:ctf:r--			#effective:---
group::---
mask::---
other::---
```
Despite the fact that the user `ctf` is allowed to read the falg, he can't do so because of the mask.
The solution is to change the mask to at least `r--`.

But I couldn't do it simply with `setfacl -m m::r-- flag`.
After wondering around, I ran `sudo -l`:
```
ctf@rd-ixiachallenge-18:~$ sudo -l
[...]
User ctf may run the following commands on rd-ixiachallenge-18:
    (ALL : ALL) NOPASSWD: /usr/bin/setfacl -m m* /home/ctf/flag
```
So the command had to be `sudo /usr/bin/setfacl -m m::r-- /home/ctf/flag`.
I ran it and it worked.
But I still couldn't read the flag.
Honestly, I have no idea why.

However, at some point I tried reading the falg right after `setfacl`-ing it, in a oneliner:
```
ctf@rd-ixiachallenge-18:~$ sudo /usr/bin/setfacl -m m::r-- /home/ctf/flag && cat flag
```
And this worked.
But I still don't understand why it had to be done like this. :(
