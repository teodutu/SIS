#!/usr/bin/python

import sys
from hashlib import sha256


hashes = []


def dummy_module():
    global hashes
    current = list(hashes)
    hash_to_match = sha256("dummy").hexdigest()
    if hash_to_match in current:
        print >> sys.stderr, "{} -> {}".format(hash_to_match, "dummy")
        hashes.remove(hash_to_match)


def main():
    global hashes
    # Read hashes from standard input.
    hashes = [line.strip() for line in sys.stdin]
    dummy_module()
    print '\n'.join(h for h in hashes)


if __name__ == "__main__":
    sys.exit(main())
