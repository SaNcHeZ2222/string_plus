#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strtok_1) {
  char str[24] = "test1/test2/test3/test4";
  char sep[10] = "/";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}
END_TEST

START_TEST(strtok_2) {
  char str[24] = "test1/test2/test3/test4";
  char sep[10] = "test1";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}
END_TEST

START_TEST(strtok_3) {
  char str[24] = "test1/test2/test3/test4";
  char sep[10] = "test2";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}
END_TEST

START_TEST(strtok_4) {
  char str[24] = "AAA BBB";
  char sep[10] = " ";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}

START_TEST(strtok_5) {
  char str[24] = "bbbbabbbb";
  char sep[10] = "c";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}

START_TEST(strtok_6) {
  char str[24] = "\0";
  char sep[10] = "c";
  ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
}

// START_TEST(strtok_7) {
//   char *str = NULL;
//   char sep[10] = "c";
//   ck_assert_pstr_eq(s21_strtok(str, sep), strtok(str, sep));
// }

Suite *test_s21_strtok(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_strtok");
  tc13 = tcase_create("case_strtok");
  tcase_add_test(tc13, strtok_1);
  tcase_add_test(tc13, strtok_2);
  tcase_add_test(tc13, strtok_3);
  tcase_add_test(tc13, strtok_4);
  tcase_add_test(tc13, strtok_5);
  tcase_add_test(tc13, strtok_6);
  // tcase_add_test(tc13, strtok_7);

  suite_add_tcase(s13, tc13);
  return s13;
}
