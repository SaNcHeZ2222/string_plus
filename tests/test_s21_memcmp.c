#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(memcmp_1) {
  unsigned char src[15] = "1234567890";
  unsigned char dst[15] = "1234563890";
  ck_assert_int_eq(s21_memcmp(src, dst, 10), memcmp(src, dst, 10));
}
END_TEST

START_TEST(memcmp_2) {
  unsigned char src[15] = "1234567890";
  unsigned char dst[15] = "1234567890";
  ck_assert_int_eq(s21_memcmp(src, dst, 10), memcmp(src, dst, 10));
}
END_TEST

START_TEST(memcmp_3) {
  unsigned char src[15] = "abs";
  unsigned char dst[15] = "abs";
  ck_assert_int_eq(s21_memcmp(src, dst, 2), memcmp(src, dst, 2));
}
END_TEST

START_TEST(memcmp_4) {
  unsigned char src[15] = "123";
  unsigned char dst[15] = "asdv";
  ck_assert_int_eq(s21_memcmp(src, dst, 10), memcmp(src, dst, 10));
}

START_TEST(memcmp_5) {
  unsigned char src[15] = "12312312";
  unsigned char dst[15] = "123;as[[]]";
  ck_assert_int_eq(s21_memcmp(src, dst, 10), memcmp(src, dst, 10));
}

Suite *test_s21_memcp(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_memcmp");
  tc13 = tcase_create("case_memcmp");
  tcase_add_test(tc13, memcmp_1);
  tcase_add_test(tc13, memcmp_2);
  tcase_add_test(tc13, memcmp_3);
  tcase_add_test(tc13, memcmp_4);
  tcase_add_test(tc13, memcmp_5);
  suite_add_tcase(s13, tc13);
  return s13;
}
