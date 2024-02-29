#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

// char *strncat(char *dest, const char *src, s21_size_t n)
/* Добавляет строку, на которую указывает src,
в конец строки, на которую указывает dest, длиной до n символов. */

START_TEST(test_strncat_1) {
  char str1[SIZE] = "HI, How are you?";
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 5;
  ck_assert_pstr_eq(s21_strncat(str1, str2, number),
                    strncat(str1, str2, number));
}
END_TEST

START_TEST(test_strncat_2) {
  char str1[200] = "HI, How are you?";  // с сайзом сега
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 55;
  ck_assert_pstr_eq(s21_strncat(str1, str2, number),
                    strncat(str1, str2, number));
}
END_TEST

START_TEST(test_strncat_3) {
  char str1[SIZE] = "";
  char *str2 = "I am fine, thanks!";
  s21_size_t number = 3;
  ck_assert_pstr_eq(s21_strncat(str1, str2, number),
                    strncat(str1, str2, number));
}
END_TEST

START_TEST(test_strncat_4) {
  char str1[SIZE] = "qazwsxedc";
  char *str2 = "";
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_strncat(str1, str2, number),
                    strncat(str1, str2, number));
}
END_TEST

START_TEST(test_strncat_5) {
  char str1[SIZE] = "\0";
  char *str2 = "qazwsxedc";
  s21_size_t number = 4;
  ck_assert_pstr_eq(s21_strncat(str1, str2, number),
                    strncat(str1, str2, number));
}
END_TEST

Suite *test_s21_strncat() {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_strncat");
  tc = tcase_create("s21_strncat_tc");

  tcase_add_test(tc, test_strncat_1);
  tcase_add_test(tc, test_strncat_2);
  tcase_add_test(tc, test_strncat_3);
  tcase_add_test(tc, test_strncat_4);
  tcase_add_test(tc, test_strncat_5);

  suite_add_tcase(s, tc);

  return s;
}
