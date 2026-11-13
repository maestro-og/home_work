#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя, иначе выводит ошибку и завершает программу
 */
int GETnum(const char *string);

/**
 * @brief проверяет, является ли среднее арифметическое a и b целым числом
 * @param a - значение, которое вводит пользователь
 * @param b - значение, которое вводит пользователь
 * @return true, если (a + b) / 2 целое, иначе false
 */
bool Check(const int a, const int b);

/**
 * @brief точка входа в программу
 * @return возвращает 0
 */
int main(){
  setlocale(LC_ALL, ".UTF-8");

  int a = GETnum("Введите значение переменной a: ");
  int b = GETnum("Введите значение переменной b: ");

  if (Check(a, b)) {
    printf("Среднее арифметическое - целое число\n");
  } 
  else {
    printf("Среднее арифметическое - не целое число\n");
  }

  return 0;
}

int GETnum( const char *string){
  printf("%s", string);
  int num = 0;
  if (scanf("%d", &num) != 1) {
    printf("Error\n");
    exit(1);
  }
  return num;
}

bool Check(const int a, const int b){
  return (a + b) % 2 == 0;
}
