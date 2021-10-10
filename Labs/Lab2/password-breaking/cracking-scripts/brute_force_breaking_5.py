from sys import exit
from hashlib import sha256
import itertools
import string


def brute_force_module(hashes):
    passwords = []

    for s in itertools.product(string.printable, repeat=5):
        s = ''.join(s)
        if len(s) == 5:
            h = sha256(s.encode()).hexdigest()
            if h in hashes:
                passwords.append((s, h))
    
    return passwords


def main():
    hashes = {line.strip() for line in open('../5chars-passwords.hash')}
    for p, h in brute_force_module(hashes):
        print(f'{p} ---> {h}')


if __name__ == "__main__":
    exit(main())


# 12^20 ---> 3d70e508663647e156f9bc43ad1a5e4166bf17a8d8e181a92733d35f2c50b667
# uUuUu ---> 27477ffdc76384f8173f638c623c1f13cfa1d480ab149aa4872d297ef0faca66
# F###Y ---> ba4b7e5b01a386f4ba4910ad14cc5b31fe9d47db2d21053c7c71bb4ca33de8ee
# L0lzz ---> d6fd118d714fcab2418783bf800f545a917c4060501257801da36384258ca560
# P00f& ---> 7ab9e83e4e7ad22147e6737419fde8914748496a95c26ae624c2ef494b47cf37
# S$$S$ ---> 82f9b09ef19a5687be586616e01d8e1e5d006dc34c88bb41b221c9f9359ae2df
# !@#$% ---> aa4dd161368601247932398ae2b8652ef7a19230e13df49175a603380afb666f
# (eof) ---> 6c50df45346d3d15c3dbf197701abc7255c89ed165cfaa9e9d8db1fe68ce2c6c
