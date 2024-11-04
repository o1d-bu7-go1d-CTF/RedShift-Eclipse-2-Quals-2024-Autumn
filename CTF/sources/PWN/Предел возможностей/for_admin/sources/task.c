#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 16

void win() {
    FILE *file = fopen("FLAG.md", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл FLAG.md\n");
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    
    fclose(file);
}

void initialize_resources() {
    int arr[10];
    int *ptr = arr;
    for (int i = 0; i < 10; i++) {
        ptr[i] = i * 2;
        printf("Resource Init Loop %d, Value: %d\n", i, ptr[i]);
        int temp = ptr[i];
        printf("Temp value: %d\n", temp);
        if (temp % 3 == 0) {
            printf("Temp is divisible by 3\n");
        } else {
            printf("Temp is not divisible by 3\n");
        }
    }
    printf("Resource initialization completed\n");
    int *junk_ptr = (int *)malloc(BUFSIZE * sizeof(int));
    if (junk_ptr) {
        for (int i = 0; i < BUFSIZE; i++) {
            junk_ptr[i] = i * 5;
            printf("Junk value: %d\n", junk_ptr[i]);
        }
        free(junk_ptr);
    }
    char *extra_str = (char *)malloc(BUFSIZE * 3);
    if (extra_str) {
        strncpy(extra_str, "Extra String", BUFSIZE * 3 - 1);
        extra_str[BUFSIZE * 3 - 1] = '\0';
        printf("Extra: %s\n", extra_str);
        free(extra_str);
    }
}

void compute_results() {
    int sum = 0;
    int *sum_ptr = &sum;
    for (int i = 0; i < BUFSIZE; i++) {
        *sum_ptr += i;
        printf("Result Sum: %d\n", *sum_ptr);
        if (*sum_ptr > 20) {
            printf("Sum exceeded 20\n");
        }
    }
    printf("Final Result: %d\n", *sum_ptr);
    char buffer[BUFSIZE * 3];
    snprintf(buffer, sizeof(buffer), "Sum is %d", sum);
    printf("Buffer: %s\n", buffer);
    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file) {
        fprintf(temp_file, "Temporary data\n");
        fclose(temp_file);
    }
}

void output_data() {
    char str[BUFSIZE] = "Data Output";
    char *str_ptr = str;
    for (int i = 0; i < BUFSIZE; i++) {
        printf("%s %d\n", str_ptr, i);
        if (i % 2 == 0) {
            printf("Even index\n");
        } else {
            printf("Odd index\n");
        }
    }
    printf("Data output completed\n");
    char *dynamic_str = (char *)malloc(BUFSIZE * 2);
    if (dynamic_str) {
        strncpy(dynamic_str, "Dynamic String", BUFSIZE * 2 - 1);
        dynamic_str[BUFSIZE * 2 - 1] = '\0';
        printf("Dynamic: %s\n", dynamic_str);
        free(dynamic_str);
    }
    int *extra_array = (int *)calloc(BUFSIZE / 2, sizeof(int));
    if (extra_array) {
        for (int i = 0; i < BUFSIZE / 2; i++) {
            extra_array[i] = i * 10;
            printf("Extra Array value: %d\n", extra_array[i]);
        }
        free(extra_array);
    }
}

void manage_resources() {
    initialize_resources();
    compute_results();
    output_data();
}

void gather_metrics() {
    int arr[BUFSIZE];
    int *ptr = arr;
    for (int i = 0; i < BUFSIZE; i++) {
        ptr[i] = i * 3;
        printf("Metrics Loop %d, Value: %d\n", i, ptr[i]);
        int temp = ptr[i];
        printf("Temp value: %d\n", temp);
        if (temp % 4 == 0) {
            printf("Temp is divisible by 4\n");
        } else {
            printf("Temp is not divisible by 4\n");
        }
    }
    printf("Metrics gathering completed\n");
    FILE *file = fopen("dummy.txt", "w");
    if (file) {
        fprintf(file, "Dummy data\n");
        fclose(file);
    }
    char *extra_buffer = (char *)malloc(BUFSIZE * 6);
    if (extra_buffer) {
        memset(extra_buffer, 'B', BUFSIZE * 6 - 1);
        extra_buffer[BUFSIZE * 6 - 1] = '\0';
        printf("Extra Buffer: %s\n", extra_buffer);
        free(extra_buffer);
    }
}

void aggregate_data() {
    int sum = 0;
    int *sum_ptr = &sum;
    for (int i = 0; i < BUFSIZE; i++) {
        *sum_ptr += i * 2;
        printf("Aggregate Sum: %d\n", *sum_ptr);
        if (*sum_ptr > 30) {
            printf("Sum exceeded 30\n");
        }
    }
    printf("Final Aggregate: %d\n", *sum_ptr);
    char *temp_str = (char *)malloc(BUFSIZE * 3);
    if (temp_str) {
        snprintf(temp_str, BUFSIZE * 3, "Temporary String %d", sum);
        printf("Temp String: %s\n", temp_str);
        free(temp_str);
    }
    int *temp_array = (int *)malloc(BUFSIZE * sizeof(int));
    if (temp_array) {
        for (int i = 0; i < BUFSIZE; i++) {
            temp_array[i] = i + 100;
            printf("Temp Array value: %d\n", temp_array[i]);
        }
        free(temp_array);
    }
}

void summarize_information() {
    char str[BUFSIZE] = "Summary Info";
    char *str_ptr = str;
    for (int i = 0; i < BUFSIZE; i++) {
        printf("%s %d\n", str_ptr, i);
        if (i % 3 == 0) {
            printf("Index divisible by 3\n");
        } else {
            printf("Index not divisible by 3\n");
        }
    }
    printf("Information summary completed\n");
    int *array = (int *)calloc(BUFSIZE, sizeof(int));
    if (array) {
        for (int i = 0; i < BUFSIZE; i++) {
            array[i] = i;
            printf("Array value: %d\n", array[i]);
        }
        free(array);
    }
    char *extra_dynamic_str = (char *)malloc(BUFSIZE * 4);
    if (extra_dynamic_str) {
        strncpy(extra_dynamic_str, "Another Dynamic String", BUFSIZE * 4 - 1);
        extra_dynamic_str[BUFSIZE * 4 - 1] = '\0';
        printf("Extra Dynamic: %s\n", extra_dynamic_str);
        free(extra_dynamic_str);
    }
}

void analyze_data() {
    gather_metrics();
    aggregate_data();
    summarize_information();
}

void evaluate_performance() {
    int arr[BUFSIZE];
    int *ptr = arr;
    for (int i = 0; i < BUFSIZE; i++) {
        ptr[i] = i * 4;
        printf("Performance Loop %d, Value: %d\n", i, ptr[i]);
        int temp = ptr[i];
        printf("Temp value: %d\n", temp);
        if (temp % 5 == 0) {
            printf("Temp is divisible by 5\n");
        } else {
            printf("Temp is not divisible by 5\n");
        }
    }
    printf("Performance evaluation completed\n");
    char *junk = (char *)malloc(BUFSIZE * 6);
    if (junk) {
        memset(junk, 'A', BUFSIZE * 6 - 1);
        junk[BUFSIZE * 6 - 1] = '\0';
        printf("Junk: %s\n", junk);
        free(junk);
    }
    int *extra_numbers = (int *)malloc(BUFSIZE * 2 * sizeof(int));
    if (extra_numbers) {
        for (int i = 0; i < BUFSIZE * 2; i++) {
            extra_numbers[i] = i * 3;
            printf("Extra Numbers: %d\n", extra_numbers[i]);
        }
        free(extra_numbers);
    }
}

void calculate_statistics() {
    int sum = 0;
    int *sum_ptr = &sum;
    for (int i = 0; i < BUFSIZE; i++) {
        *sum_ptr += i * 3;
        printf("Statistics Sum: %d\n", *sum_ptr);
        if (*sum_ptr > 40) {
            printf("Sum exceeded 40\n");
        }
    }
    printf("Final Statistics: %d\n", *sum_ptr);
    char buffer[BUFSIZE * 6];
    snprintf(buffer, sizeof(buffer), "Sum is now %d", sum);
    printf("Buffer: %s\n", buffer);
    char *extra_data = (char *)malloc(BUFSIZE * 5);
    if (extra_data) {
        memset(extra_data, 'C', BUFSIZE * 5 - 1);
        extra_data[BUFSIZE * 5 - 1] = '\0';
        printf("Extra Data: %s\n", extra_data);
        free(extra_data);
    }
}

void log_activity() {
    char str[BUFSIZE] = "Activity Log";
    char *str_ptr = str;
    for (int i = 0; i < BUFSIZE; i++) {
        printf("%s %d\n", str_ptr, i);
        if (i % 4 == 0) {
            printf("Index divisible by 4\n");
        } else {
            printf("Index not divisible by 4\n");
        }
    }
    printf("Activity log completed\n");
    int *dynamic_array = (int *)malloc(BUFSIZE * 2 * sizeof(int));
    if (dynamic_array) {
        for (int i = 0; i < BUFSIZE * 2; i++) {
            dynamic_array[i] = i * 2;
            printf("Dynamic Array value: %d\n", dynamic_array[i]);
        }
        free(dynamic_array);
    }
    FILE *log_file = fopen("log.txt", "a");
    if (log_file) {
        fprintf(log_file, "Log entry\n");
        fclose(log_file);
    }
}

void perform_analysis() {
    evaluate_performance();
    calculate_statistics();
    log_activity();
}

void process_input() {
    char buf[16];
    printf("Enter input: \n");
    return gets(buf);   
}

void execute_operations() {
    manage_resources();
    analyze_data();
    process_input();
    perform_analysis();
}

void display_menu() {
    printf("\n=== Главное меню ===\n");
    printf("1. Управление ресурсами - Инициализация и освобождение ресурсов\n");
    printf("2. Анализ данных - Сбор и обработка метрик\n");
    printf("3. Ввод данных - Получение пользовательского ввода\n");
    printf("4. Выполнение анализа - Оценка производительности и статистики\n");
    printf("5. Выход - Завершение программы\n");
    printf("====================\n");
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);

    // Set the gid to the effective gid
    // this prevents /bin/sh from dropping the privileges
    gid_t gid = getegid();
    setresgid(gid, gid, gid);

    int choice;
    int confirm_exit = 0; // Объявляем переменную здесь
    char input_buffer[BUFSIZE]; // Буфер для ввода

    do {
        display_menu();
        printf("Введите ваш выбор: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin)) {
            sscanf(input_buffer, "%d", &choice);
        }

        switch (choice) {
            case 1:
                printf("Вы выбрали: Управление ресурсами\n");
                manage_resources();
                break;
            case 2:
                printf("Вы выбрали: Анализ данных\n");
                analyze_data();
                break;
            case 3:
                printf("Вы выбрали: Ввод данных\n");
                setresgid(gid, gid, gid);
                process_input();
                break;
            case 4:
                printf("Вы выбрали: Выполнение анализа\n");
                perform_analysis();
                break;
            case 5:
                printf("Вы уверены, что хотите выйти? (1 - Да, 0 - Нет): ");
                if (fgets(input_buffer, sizeof(input_buffer), stdin)) {
                    sscanf(input_buffer, "%d", &confirm_exit);
                }
                if (confirm_exit == 1) {
                    printf("Выход из программы.\n");
                } else {
                    choice = 0; // чтобы продолжить цикл
                }
                break;
            default:
                printf("Неверный выбор, попробуйте снова.\n");
        }
    } while (choice != 5 || confirm_exit != 1);
}
