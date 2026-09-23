#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
double GETvalue();

/**
 * @brief проверяет значение на положительность
 * @param value - проверяемое значение
 */
void Checkparam(const double value);

/**
 * @brief выдает нам вычисления в зависимости от выбора пользователя
 * @param choose - значение от которого зависит формула
 * @param radius - радиус заданный пользователем
 * @return выводит или Объем шара, или Площадь поверхности шара, или НИЧЕГО (при некорректном вводе)
 */
double Choose(const short choose, const double radius);

/**
 *@brief входная точка
 *@return значение 0, если программа выполнена корректно
 */
int main(){

    setlocale(LC_ALL, "Russian");
    printf("Введи значение радиуса: ");
    double radius = GETvalue();
    Checkparam(radius);

    printf("Выбери что хочешь вычислить\nВведите '1' чтобы вычислить Объем шара\nВведите '2' чтобы вычислить Площадь поверхности шара\n");
    short choose = (short)GETvalue();
    printf("%lf",Choose(choose , radius));

    return 0;
}

double GETvalue(){
    double value = 0;
    if(!scanf("%lf", &value)){
        printf("Error\n");
        exit(1);
    }
    return value;
}

void Checkparam(const double value){
    if (value < 0){
        printf("Корректны только положительные значения\n");
        exit(1);
    }
}

double Choose(const short choose, const double radius){
    if(choose == 1){
        printf("Объем шара = ");
        return ( 4.0/3.0 * M_PI * pow(radius,3));
    }
    else if (choose == 2){
        printf("Площадь поверхности шара = ");
        return ( 4.0 * M_PI * pow(radius,2));
    }
    else{
        printf("Ввели некорректное значение");
        exit(1);
        return 0;
    }
}
