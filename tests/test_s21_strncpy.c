#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(test_strncpy_1) {
  char *src = "Hello, world!";
  char dst[4];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 3), strncpy(dst, src, 3));
}
END_TEST

START_TEST(test_strncpy_2) {
  char src[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
  char dst[6];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 4), strncpy(dst, src, 4));
}
END_TEST

START_TEST(test_strncpy_3) {
  char src[10] = "";
  char dst[6];
  ck_assert_pstr_eq(s21_strncpy(dst, src, 5), strncpy(dst, src, 5));
}
END_TEST

Suite *test_s21_strncpy() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strncpy");
  tc = tcase_create("s21_strncpy_tc");

  tcase_add_test(tc, test_strncpy_1);
  tcase_add_test(tc, test_strncpy_2);
  tcase_add_test(tc, test_strncpy_3);

  suite_add_tcase(s, tc);

  return s;
}