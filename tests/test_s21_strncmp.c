#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(test_strncmp_1) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 8), strncmp(str1, str2, 8));
}
END_TEST

START_TEST(test_strncmp_2) {
  char *str1 = "Hello, world!";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(test_strncmp_3) {
  char str1[10] = "";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

Suite *test_s21_strncmp() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strncmp");
  tc = tcase_create("s21_strncmp_tc");

  tcase_add_test(tc, test_strncmp_1);
  tcase_add_test(tc, test_strncmp_2);
  tcase_add_test(tc, test_strncmp_3);

  suite_add_tcase(s, tc);

  return s;
}