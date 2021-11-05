# Pastebin
Probably the most straightforward challenge.

I gave the website some input and received what looked like a hash, together with my output.
I thought the trick was XSS and I tried the classic `<script>alert(1);</script>`.
However, it appeared in clear text and nothing happened.

So I took a closer look at the hash.
After decrypting a few of them on [crackstation](https://crackstation.net/), I figured out that upon each request, the server increments an internal counter and responds with the `md5` hash of that counter.
Moreover, the server redirects to the page named after this `md5` hash.

But the counter was already above 3800 and, because I was solving the challenge on the day it was released, it seemed unreasonable that 3800 requests had been already sent to the server.

I assumed that probably the first 3000+ requests were pregenerated on the server and I decided to take a look at their pages and try to find the flag.
So I iterated through all numbers from 0 to 4000 and requested the pages `http://141.85.224.99:8080/ms5(number)`.
Quite unoriginally, the number whose page held the flag was `1337`.
