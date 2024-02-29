#include "../s21_string.h"

// char *strstr(const char *haystack, const char *needle)
/* Находит первое вхождение всей строки
needle (не включая завершающий нулевой символ), которая появляется в строке
haystack. */

char *s21_strstr(const char *haystack, const char *needle) {
  char *str_1 = (char *)haystack;
  int i = 0, j = 0;
  while ((str_1[j] != '\0') && (needle[i] != '\0')) {
    if (needle[i] != str_1[j])
      i = 0;
    else
      i++;
    j++;
  }
  if (needle[i] == '\0')
    return &str_1[j - i];
  else
    return NULL;
}