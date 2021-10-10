#!/usr/bin/python

import sys
from hashlib import sha256


hashes = []


def hybrid_module():
    global hashes
    current = list(hashes)
    for s in [line.strip() for line in open("../dict/words")]:
        # TODO
        pass


def main():
    global hashes
    # Read hashes from standard input.
    hashes = [line.strip() for line in sys.stdin]
    hybrid_module()
    print '\n'.join(h for h in hashes)


if __name__ == "__main__":
    sys.exit(main())
