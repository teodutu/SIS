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


def extended_module(hashes):
    passwords = []
    for s in [line.strip() for line in open("../dict/words")]:
        for s in gen_subst(s):
            h = sha256(s.encode()).hexdigest()
            if h in hashes:
                passwords.append((s, h))

    return passwords


def main():
    hashes = {line.strip() for line in open('../passwords.hash')}
    for p, h in extended_module(hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())
