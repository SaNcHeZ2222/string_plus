#include "../s21_string.h"

/*
 * Описание:
 * Функция выполняет поиск символов строки string2 в строке string1.
 * Возвращает длину начального участка строки string1 которая состоит
 * только из символов, которые являются частью строки string2.
 *
 * Возвращаемое значение:
 * Длина начального участка строки string1, содержащего только символы строки
 * string2.
 * - Если все символы строки string1 входят в строку string2, функция
 * возвращает длину всей строки string1.
 * - Если первый символ в string1 не входит в строку string2, функция возвращает
 * ноль.
 * */

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int i = 0, j = 0;
  while (str1[i]) {
    while (str2[j]) {
      if (str1[i] == str2[j]) {
        break;
      }
      j++;
    }
    if (str1[i] != str2[j]) {
      break;
    }
    i++;
    j = 0;
  }
  result = i;
  return result;
}