#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/**
 * @brief Читает одно число с клавиатуры
 * @return Введенное число 
 */
double GetValue();

/**
 * @brief Заполняет массив числами, введенными пользователем
 * @param arr Массив, который нужно заполнить
 * @param size Количество элементов в массиве
 */
void GetArray(double arr[], const int size);

/**
 * @brief Выводит массив на экран
 * @param arr Массив для вывода
 * @param size Количество элементов в массиве
 */
void PrintArray(const double arr[], const int size);

/**
 * @brief Вычисляет и выводит среднее арифметическое отрицательных чисел
 * @param arr Массив для обработки
 * @param size Количество элементов в массиве
 */
void Middle_Negative(const double arr[], const int size);

int main() {
    double arr[SIZE];
    GetArray(arr, SIZE);       
    PrintArray(arr, SIZE);     
    Middle_Negative(arr, SIZE);
    return 0;
}

double GetValue() {
    double value = 0.0;
    if (scanf("%lf", &value) != 1) {
        printf("Error\n");
        exit(1);
    }
    return value;
}

void GetArray(double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter %d-th number: ", i + 1);
        arr[i] = GetValue();
    }
}

void PrintArray(const double arr[], const int size) {
    printf("list: [");
    for (int i = 0; i < size; i++) {
        printf("%.2lf", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void Middle_Negative(const double arr[], const int size) {
    double sum = 0.0;
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
            count++;
        }
    }
    
    if (count == 0) {
        printf("negative not detected.\n");
    } else {
        printf("Middle Negative = %.4lf\n", sum / count);
    }
}
