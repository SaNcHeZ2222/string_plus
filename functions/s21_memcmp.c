#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *a = str1, *b = str2;
  while (n && *a == *b) {
    ++a;
    ++b;
    --n;
  }
  int result;
  if (n != 0)
    result = *a - *b;
  else
    result = 0;
  return result;
}