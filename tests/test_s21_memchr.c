#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

// void *memchr(const void *str, int c, s21_size_t n)
/* Выполняет поиск первого вхождения символа
c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
*/

START_TEST(test_memchr_1) {
  char str1[SIZE] = "HI, How are you?";
  char symbol = 'H';
  s21_size_t number = 7;
  ck_assert_pstr_eq(s21_memchr(str1, symbol, number),
                    memchr(str1, symbol, number));
}
END_TEST

START_TEST(test_memchr_2) {
  char str1[SIZE] = "I am fine, thanks!";
  char symbol = 'L';
  s21_size_t number = 55;
  ck_assert_pstr_eq(s21_memchr(str1, symbol, number),
                    memchr(str1, symbol, number));
}
END_TEST

START_TEST(test_memchr_3) {
  char str1[SIZE] = "QAZWSXed";
  char symbol = 'd';
  s21_size_t number = 7;
  ck_assert_pstr_eq(s21_memchr(str1, symbol, number),
                    memchr(str1, symbol, number));
}
END_TEST

/*START_TEST(test_memchr_4)
{
  char str1[SIZE] = "qazwsxedc";
  char symbol = "";
  s21_size_t number = 8;
  ck_assert_pstr_eq(s21_memchr(str1, symbol, number), memchr(str1, symbol,
number));
}
END_TEST*/

START_TEST(test_memchr_5) {
  char str1[SIZE] = "\0";
  char symbol = '\0';
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_memchr(str1, symbol, number),
                    memchr(str1, symbol, number));
}
END_TEST

Suite *test_s21_memchr() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_memchr");
  tc = tcase_create("s21_memchr_tc");

  tcase_add_test(tc, test_memchr_1);
  tcase_add_test(tc, test_memchr_2);
  tcase_add_test(tc, test_memchr_3);
  // tcase_add_test(tc, test_memchr_4);
  tcase_add_test(tc, test_memchr_5);

  suite_add_tcase(s, tc);

  return s;
}
