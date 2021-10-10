from sys import exit
from hashlib import sha256


def dictionary_module(hashes):
    passwords = []

    for s in [line.strip() for line in open("../dict/words")]:
        h = sha256(s.encode()).hexdigest()
        if h in hashes:
            passwords.append((s, h))

    return passwords


def main():
    hashes = {line.strip() for line in open('../passwords.hash')}
    for p, h in dictionary_module(hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())
