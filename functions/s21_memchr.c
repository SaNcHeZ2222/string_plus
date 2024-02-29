#include "../s21_string.h"

// void *memchr(const void *str, int c, s21_size_t n)
/* Выполняет поиск первого вхождения символа
c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
*/

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *str_1 = (char *)str;
  char *index = NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (str_1[i] == c) {
      index = &str_1[i];
      break;
    }
  }
  return index;
}