def rot_plus_7(byte):
    # Применяем ROT +7 (сдвигаем байт на +7)
    return (byte + 7) % 256

def apply_rot_plus_7_to_file(input_file, output_file):
    with open(input_file, 'rb') as f:
        # Читаем содержимое файла
        data = f.read()

    # Применяем ROT +7 к каждому байту
    transformed_data = bytearray(rot_plus_7(byte) for byte in data)

    with open(output_file, 'wb') as f:
        # Записываем измененные данные в новый файл
        f.write(transformed_data)

# Использование функции
input_filename = 'enc.jpg'
output_filename = 'new.jpg'
apply_rot_plus_7_to_file(input_filename, output_filename)

print(f'Файл {input_filename} успешно преобразован с ROT +7 и сохранен как {output_filename}.')
