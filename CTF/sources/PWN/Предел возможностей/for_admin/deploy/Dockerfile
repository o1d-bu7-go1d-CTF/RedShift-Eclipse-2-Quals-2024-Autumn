# Используем минимальный базовый образ
FROM debian:latest

# Устанавливаем необходимые пакеты
RUN apt-get update && apt-get install -y socat

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем исполняемый файл и флаг
COPY chall /app/chall
COPY FLAG.md /FLAG.md

# Устанавливаем права доступа
RUN chmod +x /app/chall && chmod 444 /FLAG.md

# Создаем пользователя для изоляции флага
RUN useradd -m ctfuser && \
    chown root:root /FLAG.md && \
    chmod 444 /FLAG.md

# Запускаем программу от имени изолированного пользователя через socat
USER ctfuser
CMD socat TCP-LISTEN:12345,reuseaddr,fork EXEC:'/app/chall'
