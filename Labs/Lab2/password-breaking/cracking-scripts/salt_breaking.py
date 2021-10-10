from sys import exit
from hashlib import sha256


def salt_module(salts, hashes):
    passwords = []

    for s in [line.strip() for line in open("../dict/words")]:
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

    for p, h in salt_module(salts, hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())
