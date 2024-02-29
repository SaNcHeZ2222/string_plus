#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *str_copy = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);
    str_copy = (char *)malloc(sizeof(char) * (len + 1));

    if (str_copy) {
      for (s21_size_t i = 0; i <= len; i++)
        str_copy[i] = (str[i] >= 65 && str[i] <= 90) ? str[i] + 32 : str[i];
      str_copy[len] = '\0';
    }
  }
  return str_copy;
}