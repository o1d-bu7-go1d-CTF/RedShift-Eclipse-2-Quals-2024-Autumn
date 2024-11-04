# Task: Header

Solve:

Решается с помощью pyton script (файл: solve.py)

1. В корневой директории есть невидимый текст что нужно делать запросы на /flag c User-Agent: Windows 98
2. Далее подсказка `not so fast need header TimeStamp %Y-%m-%d %H:%M:%S and it needs to be correct`, в тексте задания видно что это python, используется обычная библиотека datetime, метод datetime.now. На главной странице есть время сервера!
3. Добавляем хедер `TimeStamp: datetime.now().strftime("%Y-%m-%d %H:%M:%S")`
4. Далее подсказка `not so fast need header RandintStamp this is last one! GO ON!!))) {rrand} /help /help /help`
5. /help дает подсказку `the seed is last step and key is between random.randint(5000, 9999)`

Пример:

```python
def fixed_datetime_random(datetime_string, start=5000, end=9999):
    dt_object = datetime.strptime(datetime_string, "%Y-%m-%d %H:%M:%S")
    seed_value = int(dt_object.strftime("%Y%m%d%H%M%S"))
    random.seed(seed_value)
    return random.randint(start, end)
```

Создание строки для хедера шаг2        --> datetime_string = datetime.now().strftime("%Y-%m-%d %H:%M:%S") - без него не дойти до шага 3
преобразование строки в datetime ojb   --> dt_object = datetime.strptime(datetime_string, "%Y-%m-%d %H:%M:%S")
преобразование datetime ojb в число    --> seed_value = int(dt_object.strftime("%Y%m%d%H%M%S"))
/help дает подсказку                   --> random.seed(seed_value)
/help дает подсказку                   --> return random.randint(5000, 9999)

Если число близко к ответу выдается подсказка, чтобы человек понимал что он в правильном направлении:
"not SO CLOSE! {rrand}"

Flag: `EclipseCTF{834ut1ful_u53r_463nt}`