#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strrchr_1) {
  char src[11] = "0163456769";
  int ch = '6';
  ck_assert_pstr_eq(s21_strrchr(src, ch), strrchr(src, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char src[11] = "0163456769";
  int ch = ' ';
  ck_assert_pstr_eq(s21_strrchr(src, ch), strrchr(src, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char src[11] = "0163456769";
  int ch = '1';
  ck_assert_pstr_eq(s21_strrchr(src, ch), strrchr(src, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char src[11] = "ab#a";
  int ch = '#';
  ck_assert_pstr_eq(s21_strrchr(src, ch), strrchr(src, ch));
}

START_TEST(strrchr_5) {
  char src[11] = "][][][]";
  int ch = '[';
  ck_assert_pstr_eq(s21_strrchr(src, ch), strrchr(src, ch));
}

Suite *test_s21_strrchr(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_strrchr");
  tc13 = tcase_create("case_strrchr");
  tcase_add_test(tc13, strrchr_1);
  tcase_add_test(tc13, strrchr_2);
  tcase_add_test(tc13, strrchr_3);
  tcase_add_test(tc13, strrchr_4);
  tcase_add_test(tc13, strrchr_5);
  suite_add_tcase(s13, tc13);
  return s13;
}
