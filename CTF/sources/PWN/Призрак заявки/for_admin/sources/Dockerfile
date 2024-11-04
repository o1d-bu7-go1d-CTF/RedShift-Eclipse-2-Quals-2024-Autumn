# Используем базовый образ с минимальной поддержкой для запуска бинарных файлов
FROM debian:latest

# Устанавливаем socat
RUN apt-get update && apt-get install -y socat

# Создаем рабочую директорию
WORKDIR /app

# Копируем скомпилированный файл chall и флаг
COPY chall /app/chall
COPY FLAG.md /app/FLAG.md

# Устанавливаем права доступа для файла chall и флага
RUN chmod +x /app/chall && chmod 444 /app/FLAG.md

# Запуск socat для перенаправления сетевого трафика на бинарный файл
CMD socat TCP-LISTEN:12345,reuseaddr,fork EXEC:"/app/chall"
