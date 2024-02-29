#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(strerror_1) {
  for (int i = -1; i < 136; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

Suite *test_s21_strerror(void) {
  Suite *s13;
  TCase *tc13;

  s13 = suite_create("s21_strerror");
  tc13 = tcase_create("case_strerror");

  tcase_add_test(tc13, strerror_1);

  suite_add_tcase(s13, tc13);
  return s13;
}