#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(strpbrk_1) {
  char src[15] = "0123456789";
  char dst[15] = "369";
  ck_assert_pstr_eq(s21_strpbrk(src, dst), strpbrk(src, dst));
}
END_TEST

START_TEST(strpbrk_2) {
  char src[15] = "abc";
  char dst[15] = "a";
  ck_assert_pstr_eq(s21_strpbrk(src, dst), strpbrk(src, dst));
}
END_TEST

START_TEST(strpbrk_3) {
  char src[15] = "abs";
  char dst[15] = "abs";
  ck_assert_pstr_eq(s21_strpbrk(src, dst), strpbrk(src, dst));
}
END_TEST

START_TEST(strpbrk_4) {
  char src[15] = "123";
  char dst[15] = "";
  ck_assert_pstr_eq(s21_strpbrk(src, dst), strpbrk(src, dst));
}

START_TEST(strpbrk_5) {
  char src[15] = "";
  char dst[15] = "123";
  ck_assert_pstr_eq(s21_strpbrk(src, dst), strpbrk(src, dst));
}

Suite *test_s21_strpbrk(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_strpbrk");
  tc13 = tcase_create("case_strpbrk");
  tcase_add_test(tc13, strpbrk_1);
  tcase_add_test(tc13, strpbrk_2);
  tcase_add_test(tc13, strpbrk_3);
  tcase_add_test(tc13, strpbrk_4);
  tcase_add_test(tc13, strpbrk_5);
  suite_add_tcase(s13, tc13);
  return s13;
}
