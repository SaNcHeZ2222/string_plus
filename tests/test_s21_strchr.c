#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(strchr_1) {
  const char *str = "0123456789";
  int c = 's';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  const char *str = "0123456789";
  int c = '4';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  const char *str = "0123456789";
  int c = '\0';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  const char *str = "0123456\n789";
  int c = '\n';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *test_s21_strchr(void) {
  Suite *s13;
  TCase *tc13;

  s13 = suite_create("s21_strchr");
  tc13 = tcase_create("case_strchr");

  tcase_add_test(tc13, strchr_1);
  tcase_add_test(tc13, strchr_2);
  tcase_add_test(tc13, strchr_3);
  tcase_add_test(tc13, strchr_4);

  suite_add_tcase(s13, tc13);
  return s13;
}