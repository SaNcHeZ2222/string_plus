#include "../s21_string.h"

// void *memcpy(void *dest, const void *src, s21_size_t n)
/* Копирует n символов из src в dest. */

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const char *str_1 = (const char *)src;
  char *str_2 = (char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    str_2[i] = str_1[i];
  }
  return dest;
}