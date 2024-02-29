#include "../s21_string.h"

// char *strncat(char *dest, const char *src, s21_size_t n)
/* Добавляет строку, на которую указывает src,
в конец строки, на которую указывает dest, длиной до n символов. */

// char *s21_strncat(char *dest, const char *src, s21_size_t n)
// {
//     const char *str_1 = (const char *)src;
//     char *str_2 = (char *)dest;
//     s21_size_t i = 0;
//     for (s21_size_t  j = 0; i < n && str_1[i] != '\0'; j++)
//     {
//         if (str_2[j] == '\0')
//         {
//             str_2[j] = str_1[i];
//             i++;
//         }
//     }
//     dest[i+1] = '\0';
//     return dest;
// }

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
  char* ptr = dest;
  while (*ptr != '\0') {
    ptr++;
  }
  while (*src != '\0' && n > 0) {
    *ptr = *src;
    ptr++;
    src++;
    n--;
  }
  *ptr = '\0';
  return dest;
}