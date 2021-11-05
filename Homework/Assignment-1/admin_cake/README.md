# Admin cake
Using `dirb` with [this](https://github.com/danielmiessler/SecLists/blob/master/Discovery/Web-Content/raft-large-files.txt) word list, I found that the website contains the file `cookie.php`.
This told me to look at the cookies.
After logging in as `student:password`, I noticed I received 3 cookies:
- `username=student`: pretty obvious
- `salt=OWXCpMgVTR`
- `id=b3429fa45a82e9298310874c3f295ca7`

Since one of the cookies was `salt`, it was obvious that the `id` had to be a hash of the `salt + username` or `username + salt`.
After a bit of trial and error, I noticed that `id == md5(salt + username)`
I tried users such as `admin`, `administrator`, `SIS`, but none worked.

After running `dirb` a few more times with different word lists, [this one](https://github.com/danielmiessler/SecLists/blob/master/Discovery/Web-Content/raft-large-directories.txt) found a new page: `http://141.85.224.99/portaladmin`.
This page said that `Only GLaDOS can access this page`.
So I tried using `GLaDOS` as `username` in the above cookies.
And it worked!
