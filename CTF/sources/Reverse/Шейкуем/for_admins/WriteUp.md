# Task: Шейкуем

Solve:

Что имеем
- Бинарник task.bin
- Текстовик text

1. Закидываем бинарник в декомпилятор
2. Переписываем функции для понимания их работы
3. Пишем эксплоит для возвращения строки в человеческий вид
4. Закидываем строку из text в эксплоит и получаем флаг

```C
#include <stdio.h>
#include <string.h>

void reversePart(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWithPattern(char *str, int type) {
    int len = strlen(str);
    if (type == 1) {
        for (int i = 0; i < len - 1; i += 2) {
            reversePart(str, i, i + 1);
        }
    } else if (type == 2) {
        for (int i = 0; i < len; i += 3) {
            int end = (i + 2 < len) ? i + 2 : len - 1;
            reversePart(str, i, end);
        }
    } else if (type == 3) {
        for (int i = 0; i < len; i += 4) {
            int end = (i + 3 < len) ? i + 3 : len - 1;
            reversePart(str, i, end);
        }
    } else {
        reversePart(str, 0, len - 1);
    }
}

void multipleComplexReverse(char *str, int iterations) {
    int len = strlen(str);

    for (int i = 0; i < iterations; i++) {
        int start = (i % (len / 2)); 
        int end = (len - 1 - (i % (len / 2))); 
        int reverseType = i % 4; 

        if (i % 2 == 0) {
            reversePart(str, start, end);
        } else {
            reverseWithPattern(str, reverseType);
        }
    }
}

void restoreString(char *str, int iterations) {
    int len = strlen(str);

    for (int i = iterations - 1; i >= 0; i--) {
        int start = (i % (len / 2)); 
        int end = (len - 1 - (i % (len / 2))); 
        int reverseType = i % 4; 

        if (i % 2 == 0) {
            reversePart(str, start, end);
        } else {
            reverseWithPattern(str, reverseType);
        }
    }
}

int main() {
    char str[100] = "";
    int iterations = 10;

    restoreString(str, iterations);
    printf("Восстановленная строка: %s\n", str);

    return 0;
}
```

Flag: `EclipseCTF{d0nt_sh4k3_m3_m0r3!}`