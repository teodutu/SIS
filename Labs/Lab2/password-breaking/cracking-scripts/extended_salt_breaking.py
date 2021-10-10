from sys import exit
from hashlib import sha256
from copy import deepcopy


SUBST = {'a': '@', 'e': '3', 'i': '!', 'o': '0', 's': '$'}
PUNCTUATION = ['.', '...', '!', '?']


def gen_subst(string):
    subst = ['']
    for c in string:
        subst = [s + c for s in subst]
        if c in SUBST:
            subst += [s[:-1] + SUBST[c] for s in subst]            

    subst_punct = deepcopy(subst)
    for s in subst:
        subst_punct += [s + p for p in PUNCTUATION];      

    return subst_punct


def extended_salt_module(salts, hashes):
    passwords = []

    for s in [line.strip() for line in open("../dict/words")]:
        for s in gen_subst(s):
            for salt in salts:
                b_salt = bytes.fromhex(salt)
                h = sha256(s.encode() + b_salt).hexdigest()
                if h in hashes:
                    passwords.append((f'{s} + {salt}', h + salt))

                h = sha256(b_salt + s.encode()).hexdigest()
                if h in hashes:
                    passwords.append((f'{salt} + {s}', salt + h))

    return passwords


def main():
    long_hashes = [line.strip() for line in open('../passwords.hash') if len(line) == 75]
    salts = [h[:10] for h in long_hashes] + [h[-10:] for h in long_hashes]
    hashes = {h[10:] for h in long_hashes} | {h[:-10] for h in long_hashes}

    for p, h in extended_salt_module(salts, hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())
