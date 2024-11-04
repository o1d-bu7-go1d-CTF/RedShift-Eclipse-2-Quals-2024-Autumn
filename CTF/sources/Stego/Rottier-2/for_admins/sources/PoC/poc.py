from PIL import Image

def restore_image_layers(image_path, layer_width=16):
    # Открываем изображение
    with Image.open(image_path) as img:
        width, height = img.size
        
        # Проверяем, что изображение 1024x1024
        if width != 1024 or height != 1024:
            print("[-] Изображение должно быть 1024x1024 пикселей.")
            return
        
        # Создаем новое изображение для сохранения результата
        restored_img = img.copy()
        
        # Углы восстановления в том же порядке, что и для оригинального вращения
        rotations = [0, -270, -180, -90]  # Начнем с 0° и обратный порядок
        rotation_index = 0  # Начальный индекс вращения для восстановления
        
        # Начинаем восстановление с краев к центру
        num_layers = width // (2 * layer_width)  # Число слоев по ширине 16 пикселей
        
        for layer in range(num_layers):
            # Вычисляем координаты текущего слоя
            left = layer * layer_width
            upper = layer * layer_width
            right = width - (layer * layer_width)
            lower = height - (layer * layer_width)
            
            # Извлекаем слой (внешний квадрат)
            block = img.crop((left, upper, right, lower))
            
            # Поворачиваем слой на обратный угол
            rotated_block = block.rotate(rotations[rotation_index])
            
            # Вставляем восстановленный слой обратно
            restored_img.paste(rotated_block, (left, upper))
            
            # Переходим к следующему углу поворота
            rotation_index = (rotation_index + 1) % len(rotations)
        
        # Сохраняем восстановленное изображение
        restored_img_name = 'restored_image.png'
        restored_img.save(restored_img_name)
        print(f"[+] Восстановленное изображение сохранено как {restored_img_name}")

# Пример использования
rotated_image_path = 'layer_rotated_image.png'  # Путь к повернутому изображению
restore_image_layers(rotated_image_path, 16)
