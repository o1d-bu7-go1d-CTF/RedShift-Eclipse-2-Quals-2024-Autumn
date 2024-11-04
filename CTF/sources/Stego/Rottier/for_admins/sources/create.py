# Task Creator for "Rottier"
# Author: o1d_bu7_go1d

from PIL import Image


# Функция для получения размеров изображения
def get_image_size(image_path):
    try:
        with Image.open(image_path) as img:
            width, height = img.size
            return width, height
    except Exception as e:
        print(f"Error opening image: {e}")
        return None


# Функция для реализации поворота квадратов изображения
def rotate_image_blocks(image_path, block_size):
    # Открываем изображение
    with Image.open(image_path) as img:
        width, height = img.size
        
        # Проверяем, что изображение 1024x1024
        if width != 1024 or height != 1024:
            print("[-] Изображение должно быть 1024x1024 пикселей.")
            return
        
        # Создаем новое изображение для сохранения результата
        rotated_img = Image.new('RGB', (width, height))
        
        # Устанавливаем углы вращения в порядке
        rotations = [90, 180, 270, 0]  # 0 градусов для эквивалента 360
        rotation_index = 0  # Начальный индекс вращения

        # Перебираем блоки 64x64 по всему изображению
        for y in range(0, height, block_size):
            for x in range(0, width, block_size):
                # Извлекаем блок 64x64
                block = img.crop((x, y, x + block_size, y + block_size))
                
                # Поворачиваем блок на заданный угол
                rotated_block = block.rotate(rotations[rotation_index])
                
                # Вставляем повернутый блок в результирующее изображение
                rotated_img.paste(rotated_block, (x, y))
                
                # Переходим к следующему углу поворота
                rotation_index = (rotation_index + 1) % len(rotations)
        
        # Сохраняем новое изображение
        new_img_name = 'rotated_image.png'
        rotated_img.save(new_img_name)
        print(f"[+] Обработанное изображение сохранено как {new_img_name}")


# Пример использования:
image_path = 'raw.jpg'  # Укажите путь к изображению
size = get_image_size(image_path)

if size:
    print(f"[+] Размер изображения: {size[0]}x{size[1]} пикселей")
else:
    print(f"[-] Не удалось получить размер изображения {image_path}")

rotate_image_blocks(image_path, 64)