#!/usr/bin/python

#########################################
# This file showcases the use of pexpect
# for writing shell-interactive programs.
#########################################

import pexpect
import re
import string

# We call the target program, as you would do in bash
proc = pexpect.spawn("./sidechannel")

for s in string.printable:
    # Expect-like statements probe the program's output.
    ## Expect_exact looks for an exact occurence of a string.
    proc.expect_exact(">> Password: ")

    # We can send input via sendline.
    proc.sendline("{}".format(s))

    # Get response.
    res = proc.readline()
    res = proc.readline()

    ## Get time.
    tokens = re.split("[][]", res)
    if len(tokens) < 3:
        break
    time = int(tokens[1])

    # Let's see what we got.
    print "Password '{}' takes {}".format(s, time)
