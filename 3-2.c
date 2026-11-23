#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/*
- @brief считывает целое число с клавиатуры
- @param message - приглашение ко вводу
- @return введенное целое число
*/
int getInt(const char* message);

/*
- @brief считывает вещественное число с клавиатуры
- @param message - приглашение ко вводу
- @return введенное вещественное число
*/
double getValue(const char* message);

/*
- @brief проверяет, является ли количество элементов положительным
- @param n - количество элементов ряда
*/
void checkPositive(const int n);

/*
- @brief проверяет, является ли точность положительной
- @param e - заданная точность (эпсилон)
*/
void checkEpsilon(const double e);

/*
- @brief вычисляет сумму первых n членов ряда
- @param n - количество членов ряда
- @return сумма первых n членов ряда
*/
double sumN(const int n);

/*
- @brief вычисляет сумму членов ряда, по модулю не меньших заданного порога
- @param e - порог точности (эпсилон)
- @return сумма членов ряда с заданной точностью
*/
double sumE(const double e);

/*
- @brief вычисляет рекуррентный коэффициент для перехода к следующему члену ряда
- @param i - индекс текущего шага
- @return значение рекуррентного коэффициента
*/
double getCoef(const int i);

/*
- @brief точка входа в программу
- @return возвращает 0, если программа выполнена корректно
*/
int main(){
    int n = getInt("Enter n: ");
    checkPositive(n);
    double e = getValue("Enter e: ");
    checkEpsilon(e);
    printf("Sum of %d elements is: %.5lf\n", n, sumN(n));
    printf("Sum of elements not less than %lf is: %.5lf\n", e, sumE(e));
    return 0;
}

double getValue(const char* message){
    if (message != NULL){
        printf("%s\n", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1){
        printf("Input error");
        exit(1);
    }
    return value;
}

int getInt(const char* message){
    if (message != NULL){
        printf("%s\n", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1){
        printf("Input error");
        exit(1);
    }
    return value;
}

void checkPositive(const int n){
    if (n <= 0){
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e){
    if (e <= 0){
        printf("Error, e have to be positive\n");
        exit(1);
    }
}

double getCoef(const int i){
    return -1.0 / ((i + 3.0) * (i + 4.0));
}

double sumN(const int n){
    double a = 1.0 / 12;
    double result = a;
    for (int i = 0; i < n; i++){
        a *= getCoef(i);
        result += a;
    }
    return result;
}

double sumE(const double e){
    double a = 1.0 / 12;
    double result = 0;
    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++){
        result += a;
        a *= getCoef(i);
    }
    return result;
}
