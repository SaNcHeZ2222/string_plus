#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result;
  if (str1 == NULL || str2 == NULL) {
    result = NULL;
  } else {  // Добавил всё в else
    int flag = 1;
    while (*str1 != '\0' && flag == 1) {
      const char *temp;
      temp = str2;
      while (*temp != '\0' && flag == 1) {
        if (*str1 == *temp) {
          result = (char *)str1;
          flag = 0;
        }
        temp++;
      }
      str1++;
    }
    if (flag == 1) result = NULL;
  }
  return result;
}