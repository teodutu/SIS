#########################################
# This file showcases the use of pexpect
# for writing shell-interactive programs.
#########################################

from sys import base_exec_prefix
import pexpect
import re

# We call the target program, as you would do in bash
proc = pexpect.spawn("./sidechannel")

max_time = 0
art = ''
for s in open('./dict/articles'):
    s = s.strip()
    proc.expect_exact(">> Password: ")
    proc.sendline(s)

    res = proc.readline()
    res = proc.readline()

    tokens = re.split("[][]", res.decode())
    if len(tokens) < 3:
        break
    time = int(tokens[1])

    if time > max_time:
        max_time = time
        art = s


adj = ''
for s in open('./dict/adjectives'):
    s = s.strip()
    proc.expect_exact(">> Password: ")
    proc.sendline(f'{art} {s}')

    res = proc.readline()
    res = proc.readline()

    tokens = re.split("[][]", res.decode())
    if len(tokens) < 3:
        break
    time = int(tokens[1])

    if time > max_time:
        max_time = time
        adj = s


noun = ''
for s in open('./dict/nouns'):
    s = s.strip()

    try:
        proc.expect_exact('>> Password: ')
    except:
        print(f'Password is: \"{art} {adj} {noun}\"')
        break

    proc.sendline(f'{art} {adj} {s}')

    res = proc.readline()
    res = proc.readline()

    tokens = re.split("[][]", res.decode())
    if len(tokens) < 3:
        break
    time = int(tokens[1])

    if time > max_time:
        max_time = time
        noun = s
