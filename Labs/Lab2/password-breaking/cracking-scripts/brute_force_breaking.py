from sys import exit
from hashlib import sha256
import itertools
import string


def brute_force_module(hashes):
    passwords = []

    for s in itertools.product(string.printable, repeat=4):
        s = ''.join(s)
        if len(s) == 4:
            h = sha256(s.encode()).hexdigest()
            if h in hashes:
                passwords.append((s, h))
    
    return passwords


def main():
    hashes = {line.strip() for line in open('../passwords.hash')}
    for p, h in brute_force_module(hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())
