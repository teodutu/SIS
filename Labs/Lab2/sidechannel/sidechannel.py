#!/usr/bin/python3

import time
import random

def check(inp, password):
    n = min(len(inp), len(password))

    for i in range(n):
        if inp[i] != password[i]:
            return False
        time.sleep(0.001)

    if len(inp) != len(password):
        return False

    return True

def read_file(filename):
    f = open(filename, "r")
    lines = f.readlines()
    lines = [l.strip() for l in lines]
    f.close()

    return lines

def generate_pass(articles, adjectives, nouns):
    part1 = random.choice(articles)
    part2 = random.choice(adjectives)
    part3 = random.choice(nouns)

    return part1 + ' ' + part2 + ' ' + part3

def read_files():
    articles   = read_file("dict/articles")
    nouns      = read_file("dict/nouns")
    adjectives = read_file("dict/adjectives")

    return (articles, adjectives, nouns)

def main ():
    articles, adjectives, nouns = read_files()
    password = generate_pass(articles, adjectives, nouns)

    while True:
        inp = input(">> Password: ")
        start = time.time()
        res = check(inp, password)
        end = time.time()
        print("Elapsed time [%d] usec\n" % ((end-start) * 10000000))

        if res:
            print('>> Access granted!')

if __name__ == "__main__":
    main()
