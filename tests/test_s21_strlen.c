#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(test_strlen_1) {
  char *src = "Hello, world!";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_strlen_2) {
  char src[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(test_strlen_3) {
  char src[10] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

Suite *test_s21_strlen() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strlen");
  tc = tcase_create("s21_strlen_tc");

  tcase_add_test(tc, test_strlen_1);
  tcase_add_test(tc, test_strlen_2);
  tcase_add_test(tc, test_strlen_3);

  suite_add_tcase(s, tc);

  return s;
}