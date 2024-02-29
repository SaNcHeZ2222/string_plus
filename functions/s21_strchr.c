//  Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
//  которую указывает аргумент str.

#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = NULL;
  if (c < 0 || c > 127) {
    ;
  } else {
    int n = (int)s21_strlen(str);
    for (int i = 0; i <= n; i++) {
      if (str[i] == c) {
        res = (char *)str + i;
        break;
      }
    }
  }
  return res;
}
