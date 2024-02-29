#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(memset_1) {
  unsigned char str[10] = "oooooooooo";
  int c = 'S';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_2) {
  unsigned char str[10] = "oooooooooo";
  int c = '\0';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_3) {
  unsigned char str[10] = "oooooooooo";
  int c = 's';
  s21_size_t n = 0;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_4) {
  unsigned char str[10] = "oooooooooo";
  int c = 's';
  s21_size_t n = 10;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

Suite *test_s21_memset(void) {
  Suite *s13;
  TCase *tc13;

  s13 = suite_create("s21_memset");
  tc13 = tcase_create("case_memset");

  tcase_add_test(tc13, memset_1);
  tcase_add_test(tc13, memset_2);
  tcase_add_test(tc13, memset_3);
  tcase_add_test(tc13, memset_4);

  suite_add_tcase(s13, tc13);
  return s13;
}