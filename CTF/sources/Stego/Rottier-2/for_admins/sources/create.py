# Task Creator for "Rottier-2"
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


# Функция для реализации поворота областей изображения
def rotate_image_layers(image_path, layer_width):
    # Открываем изображение
    with Image.open(image_path) as img:
        width, height = img.size
        
        # Проверяем, что изображение 1024x1024
        if width != 1024 or height != 1024:
            print("[-] Изображение должно быть 1024x1024 пикселей.")
            return
        
        # Создаем новое изображение для сохранения результата
        rotated_img = img.copy()
        
        # Устанавливаем углы вращения в обратном порядке
        rotations = [0, 270, 180, 90]  # Начнем с 0° и обратный порядок
        rotation_index = 0  # Начальный индекс вращения
        
        # Начинаем вращение с краев к центру
        num_layers = width // (2 * layer_width)  # Число слоев по ширине 16 пикселей
        
        for layer in range(num_layers):
            # Вычисляем координаты текущего слоя
            left = layer * layer_width
            upper = layer * layer_width
            right = width - (layer * layer_width)
            lower = height - (layer * layer_width)
            
            # Извлекаем слой (внешний квадрат)
            block = img.crop((left, upper, right, lower))
            
            # Поворачиваем слой на заданный угол
            rotated_block = block.rotate(rotations[rotation_index])
            
            # Вставляем повернутый слой обратно
            rotated_img.paste(rotated_block, (left, upper))
            
            # Переходим к следующему углу поворота
            rotation_index = (rotation_index + 1) % len(rotations)
        
        # Сохраняем новое изображение
        new_img_name = 'layer_rotated_image.png'
        rotated_img.save(new_img_name)
        print(f"[+] Обработанное изображение сохранено как {new_img_name}")


# Пример использования:
image_path = 'raw.jpg'  # Укажите путь к изображению
size = get_image_size(image_path)

if size:
    print(f"[+] Размер изображения: {size[0]}x{size[1]} пикселей")
else:
    print(f"[-] Не удалось получить размер изображения {image_path}")

rotate_image_layers(image_path, 16)