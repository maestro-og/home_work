#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>

/**
 * @brief вычисление y при x > 2.5
 * @param x - значение, которое вводит пользователь
 * @param a - значение параметра a
 * @return возвращает y
 */
double y_bigger(const double x,const double a);

/**
 * @brief вычисление y при x <= 2.5
 * @param x - значение параметра x
 * @param a - значение параметра a
 * @return возвращает y
 */
double y_smaller(const double x,const double a);

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
double GETnum();

/**
 * @brief возвращает значение "y" в зависимости от значения "x"
 * @param x - значение, которое вводит пользователь
 * @param a - значение парамтера 
 */
double Choose(const double x, const double a);

/**
 * @brief точка входа в программу
 * @return возвращает 0
 */
int main(){
  setlocale(LC_ALL, ".UTF-8");
  const double a = 2.5;
  printf("Введите значение для переменной x: ");
  double x = GETnum();

  printf("y = %lf",Choose(x,a));

  return 0;
}

double y_bigger(const double x,const double a){
  return x * pow((x-a),1.0/3.0);
}

double y_smaller(const double x,const double a){
  return x * sin(a) * x;
}

double GETnum(){
  double value = 0.0;
  if (scanf("%lf",&value) != 1){
    printf("Error");
    exit(1);
  }
  return value;
}

double Choose(const double x, const double a){
  if (x > a){
    return y_bigger(x,a);
  }
  else{
    return y_smaller(x,a);
  }
}
