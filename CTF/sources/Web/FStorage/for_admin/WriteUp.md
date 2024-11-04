# Task: FStorage

Solve:

На хранилище присутствует функция разархивации архивов. Если в Linux создать symlink и заархивировать с необходимыми параметрами, тогда получится сделать архив с symlink.
- mkdir TEST_DIR
- ln -s /etc/passwd /path/to/TEST_DIR
- zip --symlinks -r ARCHIVE.zip TEST_DIR/

Тем самым в хранилище присутствует уязвимость (если разархивировать полученный архив), т.к оно будет читать путь с symlink.

Чтобы узнать какие файлы необходимо прочитать узнаем где лежит скрипт создав символическую ссылку на **/proc/self/cmdline**, от туда получаем, что скрипт лежит в **/app/app.py**.

В коде находим SQLite файл с базой:
- app.config['SQLALCHEMY_DATABASE_URI'] =  'sqlite:///'  + os.path.join(app.root_path, 'users.db')

Качаем базу, заходим на админа. Там видим файл SECRET_CONTENT.txt, открываем и получаем флаг.

Flag: `EclipseCTF{F1na11y_g0t_th6_Sup6r_S6cr6t}`