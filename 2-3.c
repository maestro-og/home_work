#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief считывает число + проверка на корректность ввода
 * @return возвращает число пользователя , иначе выводит ошибку
 */
int GETnum();

/**
 * @brief проверет среднее арефметическое на натуральность
 * @param a - значение, которое вводит пользователь
 * @param b - значение, которое вводит пользователь
 */
void Check(const int a, const int b);


/**
 * @brief точка входа в программу
 * @return возвращает 0
 */
int main(){
  setlocale(LC_ALL, ".UTF-8");
  printf("Введите значение пременной a: ");
  int a = GETnum();
  printf("Введите значение пременной b: ");
  int b = GETnum();
  Check(a,b);

  return 0;
}

int GETnum(){
  int num = 0;
  if (scanf("%d", &num) != 1) {
    printf("Error");
    exit(1);
  }
  return num;
}

void Check(const int a, const int b){
  if ((a + b) % 2 != 0){
    printf("НЕ ЦЕЛОЕ");
    exit(1);
  }
  printf("ЦЕЛОЕ");
}
