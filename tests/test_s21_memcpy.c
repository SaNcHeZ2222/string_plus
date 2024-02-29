#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

// void *memcpy(void *dest, const void *src, s21_size_t n)
/* Копирует n символов из src в dest. */

START_TEST(test_memcpy_1) {
  char str1[SIZE] = "HI, How are you?";
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 5;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, number), memcpy(str1, str2, number));
}
END_TEST

START_TEST(test_memcpy_2) {
  char str1[200] = "HI, How are you?";
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 55;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, number), memcpy(str1, str2, number));
}
END_TEST

START_TEST(test_memcpy_3) {
  char str1[SIZE] = "";
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, number), memcpy(str1, str2, number));
}
END_TEST

START_TEST(test_memcpy_4) {
  char str1[SIZE] = "qazwsxedc";
  char *str2 = "";
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, number), memcpy(str1, str2, number));
}
END_TEST

START_TEST(test_memcpy_5) {
  char str1[SIZE] = "\0";
  char *str2 = "qazwsxedc";
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, number), memcpy(str1, str2, number));
}
END_TEST

Suite *test_s21_memcpy() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_memcpy");
  tc = tcase_create("s21_memcpy_tc");

  tcase_add_test(tc, test_memcpy_1);
  tcase_add_test(tc, test_memcpy_2);
  tcase_add_test(tc, test_memcpy_3);
  tcase_add_test(tc, test_memcpy_4);
  tcase_add_test(tc, test_memcpy_5);

  suite_add_tcase(s, tc);

  return s;
}
