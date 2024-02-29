#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = NULL;

  while (*str != '\0') {
    if (*str == c) {
      res = (char *)str;
    }
    str++;
  }

  return res;
}
