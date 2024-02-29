#include "../s21_string.h"

/* Возвращает длину строки C str .
  Длина строки C определяется завершающим нулевым символом:
  длина строки C равна количеству символов между началом строки и
  завершающим нулевым символом (без учета самого завершающего нулевого символа).

  Не следует путать это с размером массива, содержащего строку.
  Например: определяет массив символов размером 100 символов , но строка C,
  с помощью которой был инициализирован mystr , имеет длину всего 11 символов.
  Таким образом, хотя sizeof(mystr) оценивается как 100 , strlen(mystr)
  возвращает 11 . В C++ char_traits::length реализует то же поведение
*/

s21_size_t s21_strlen(const char *src) {
  s21_size_t strlen = 0;
  while (*src++) {
    strlen++;
  }
  return strlen;
}
