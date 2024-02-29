#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

// char *strstr(const char *haystack, const char *needle)
/* Находит первое вхождение всей строки
needle (не включая завершающий нулевой символ), которая появляется в строке
haystack. */

START_TEST(test_strstr_1) {
  char *str1 = "rt fdsafgdgsdfsaf qazwx?";
  char *str2 = "fdsafgdgsdfsaf!";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_2) {
  char *str1 = "fdsafgdgsdfsaf!";
  char *str2 = "rt fdsafgdgsdfsaf qazwx?";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_3) {
  char *str1 = "";
  char *str2 = "I am fine, thanks!";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_4) {
  char *str1 = "qazwsxedc";
  char *str2 = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_5) {
  char *str1 = "qazwsxedc";
  char *str2 = "qazwsxedc";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_6) {
  char *str1 = "\0";
  char *str2 = "qazwsxedc";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_7) {
  char *str1 = "qazwsxedc";
  char *str2 = "\0";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *test_s21_strstr() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strstr");
  tc = tcase_create("s21_strstr_tc");

  tcase_add_test(tc, test_strstr_1);
  tcase_add_test(tc, test_strstr_2);
  tcase_add_test(tc, test_strstr_3);
  tcase_add_test(tc, test_strstr_4);
  tcase_add_test(tc, test_strstr_5);
  tcase_add_test(tc, test_strstr_6);
  tcase_add_test(tc, test_strstr_7);

  suite_add_tcase(s, tc);

  return s;
}
