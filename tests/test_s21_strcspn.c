#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(test_strcspn_1) {
  char *str1 = "Hello, world!";
  char *str2 = "Aloha!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_2) {
  char *str1 = "Hello, world!";
  char *str2 = "Taburetka";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_3) {
  char str1[10] = "";
  char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *test_s21_strcspn() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strcspn");
  tc = tcase_create("s21_strcspn_tc");

  tcase_add_test(tc, test_strcspn_1);
  tcase_add_test(tc, test_strcspn_2);
  tcase_add_test(tc, test_strcspn_3);

  suite_add_tcase(s, tc);

  return s;
}