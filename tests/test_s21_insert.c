#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

START_TEST(insert_1) {
  const char *crc = "aaabbb";
  const char *str = " ";
  s21_size_t start_index = 3;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "aaa bbb");
}
END_TEST

START_TEST(insert_2) {
  const char *crc = "oooooooooo";
  const char *str = "123";
  s21_size_t start_index = 0;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "123oooooooooo");
}
END_TEST

START_TEST(insert_3) {
  const char *crc = "oooooooooo";
  const char *str = "123";
  s21_size_t start_index = 10;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "oooooooooo123");
}
END_TEST

START_TEST(insert_4) {
  const char *crc = "oooooooooo";
  const char *str = "123";
  s21_size_t start_index = 1.3;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "o123ooooooooo");
}
END_TEST

START_TEST(insert_5) {
  const char *crc = "oooooooooo";
  const char *str = "";
  s21_size_t start_index = 5;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "oooooooooo");
}
END_TEST

START_TEST(insert_6) {
  const char *crc = "";
  const char *str = "123";
  s21_size_t start_index = 0;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "123");
}
END_TEST

START_TEST(insert_7) {
  const char *crc = "oooooooooo";
  const char *str = NULL;
  s21_size_t start_index = 3;
  ck_assert_str_eq(s21_insert(crc, str, start_index), "oooooooooo");
}
END_TEST

START_TEST(insert_8) {
  const char *crc = NULL;
  const char *str = "123";
  s21_size_t start_index = 0;
  ck_assert_ptr_null(s21_insert(crc, str, start_index));
}
END_TEST

Suite *test_s21_insert(void) {
  Suite *s13;
  TCase *tc13;

  s13 = suite_create("s21_insert");
  tc13 = tcase_create("case_insert");

  tcase_add_test(tc13, insert_1);
  tcase_add_test(tc13, insert_2);
  tcase_add_test(tc13, insert_3);
  tcase_add_test(tc13, insert_4);
  tcase_add_test(tc13, insert_5);
  tcase_add_test(tc13, insert_6);
  tcase_add_test(tc13, insert_7);
  tcase_add_test(tc13, insert_8);

  suite_add_tcase(s13, tc13);
  return s13;
}