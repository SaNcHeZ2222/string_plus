#include "../s21_string.h"

/* Сканирует str1 на предмет первого появления любого из символов,
  входящих в str2 , и возвращает количество символов str1 ,
  прочитанных до этого первого появления.

  Поиск включает завершающие нулевые символы. Таким образом,
  функция вернет длину строки str1 , если ни один из символов строки str2 не
  найден в строке str1 .
*/

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *temp_str1 = str1;
  s21_size_t count_first = 0;
  s21_size_t count_second = s21_strlen(str1);
  while (*str2 != '\0') {
    while (*str1 != '\0') {
      if (*str1 != *str2) {
        str1++;
        count_first++;
      } else {
        break;
      }
    }
    str2++;
    if (count_first <= count_second) {
      count_second = count_first;
      count_first = 0;
    }
    count_first = 0;
    str1 = temp_str1;
  }
  return count_second;
}