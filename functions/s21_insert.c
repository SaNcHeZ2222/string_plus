// void *insert(const char *src, const char *str, s21_size_t start_index)
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL

#include "../s21_string.h"

/*#include <string.h>

int main() {
    const char *crc = NULL;
    const char *str = "222";
    s21_size_t start_index = 10;
    printf("%s\n", crc);
    printf("%s\n", s21_insert(crc, str, start_index));
}*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = NULL;
  s21_size_t src_len = 0, str_len = 0;
  if (src == NULL)
    return NULL;  // src_len = 0;
  else
    src_len = s21_strlen(src);
  if (str == NULL)
    str_len = 0;
  else
    str_len = s21_strlen(str);

  s21_size_t all_len = src_len + str_len;
  if (start_index <= src_len) {
    res = (char *)calloc(src_len + str_len + 1, sizeof(char));
  }
  if (res) {
    for (s21_size_t i = 0; i < all_len; i++) {
      if (i < start_index) {
        res[i] = src[i];
      } else if (i < str_len + start_index) {
        res[i] = str[i - start_index];
      } else {
        res[i] = src[i - str_len];
      }
    }
    res[all_len] = '\0';  // .
  }
  return (void *)res;
}
