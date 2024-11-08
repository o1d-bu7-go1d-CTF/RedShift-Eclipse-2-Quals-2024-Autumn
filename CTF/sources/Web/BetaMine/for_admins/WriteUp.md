# Task: BetaMine

Solve:

Смотрим исходники, и замечаем, что один из админских методов (на сброс пароля) доступен без проверок на админа

```php
Route::post('/reset_password', [AdminController::class, 'resetPassword']);
```

Сбрасываем пароль и заходим на учетную запись админа

```
POST /api/admin/reset_password

user_id=1
```

Осмотрев функционал админ-панели можно заметить, что в тесте веб-хука можно отправлять запросы на внутренние сервисы (**однако только http,https**). Из внутренних сервисов присутствуют **mysql** и **Minecraft сервер**.

Посмотрев на Minecraft сервер можно заметить два плагина:
- **RedshiftChecker-1.0-SNAPSHOT.jar**
- **RedshiftControl-1.0-SNAPSHOT.jar**

Изучив исходники данных плагинов через декомпилятор Java можно заметить следующий функционал:
- *RedshiftChecker - если юзер оператор, то при заходе сервер отдает флаг*
- *RedShiftControl - предназначен для выполнения команд через порт 25575 (как альтернатива RCON)*

Нас интересует RedShiftControl. Плагин не требует пароля и из данных берет сразу же команду **(но есть разделитель по \n)**.
Протокол HTTP в самом начале отправляет метод, путь и версию протокола:

```
Пример: 
METHOD /xxx HTTP/1.1
```

Нас интересует METHOD, так как он стоит самый первый и в него можно прописать команду. Вписываем в method команду на выдачу оператора на сервере (op NICKNAME), а в качестве URL: http://mine:25575/ в message можно написать что угодно, это нас не интересует. По итогу получаем следующий запрос на тест вебхука:

```
POST /api/admin/test_webhook HTTP/1.1

{"method":"op NICKNAME\na","url":"http://mine:25575/","message":"qwe"}
```

> Важно, чтобы ник с которого вы заходите был написан капсом!

Заходим на сервер и получаем флаг.

Flag: `EclipseCTF{W0w_y0u_g0t_1nT0_th1s_S6rv6r}`