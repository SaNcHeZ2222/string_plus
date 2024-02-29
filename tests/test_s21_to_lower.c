#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(test_to_lower_1) {
  const char *src = "Hello, world!";
  ck_assert_str_eq(s21_to_lower(src), "hello, world!");
}
END_TEST

START_TEST(test_to_lower_2) {
  char src[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
  ck_assert_str_eq(s21_to_lower(src), "hello");
}
END_TEST

START_TEST(test_to_lower_3) {
  char src[10] = "";
  ck_assert_str_eq(s21_to_lower(src), "");
  ;
}
END_TEST

START_TEST(test_to_lower_4) {
  const char *src = NULL;
  ck_assert_ptr_null(s21_to_lower(src));
}

Suite *test_s21_to_lower() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_to_lower");
  tc = tcase_create("s21_to_lower_tc");

  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);

  suite_add_tcase(s, tc);

  return s;
}