/* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
 *  указывает аргумент str.*/

#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  /* Нет необходимости.
  if (n > s21_strlen(str)) {
    printf("zsh: illegal hardware instruction ");  // прописать ошибку и
                                                   // сообщение о ней.
    // zsh: bus error  ./a.out
    // В зависимости от того как задан массив через * или [10] сообщения об
    // ошибке разные :(
    return NULL;  // НЕверно
  }*/
  unsigned char *temp_str = str;

  for (; n > 0; n--) {
    *temp_str++ = (unsigned char)c;
    //  *temp_str++;
  }

  return (void *)str;
}