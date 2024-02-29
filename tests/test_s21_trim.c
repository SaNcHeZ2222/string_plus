#include <string.h>

#include "../s21_string.h"
#include "s21_string_test.h"

// START_TEST(trim_1) {
//   const char *src = "azaba01234aa56789aaazba";
//   const char *trim_chars = "abz";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "01234aa56789");
// }
// END_TEST

// START_TEST(trim_2) {
//   const char *src = "azaba01234aa56789aaaaaa";
//   const char *trim_chars = "abz";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "01234aa56789");
// }
// END_TEST

// START_TEST(trim_3) {
//   const char *src = "aaaa01234aa56789";
//   const char *trim_chars = "a";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "01234aa56789");
// }
// END_TEST

// START_TEST(trim_4) {
//   const char *src = "01234aa56789aaaa";
//   const char *trim_chars = "a";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "01234aa56789");
// }
// END_TEST

// START_TEST(trim_5) {
//   const char *src = "01234aa56789";
//   const char *trim_chars = "";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "01234aa56789");
// }
// END_TEST

// START_TEST(trim_6) {
//   const char *src = "";
//   const char *trim_chars = "";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "");
// }
// END_TEST

// START_TEST(trim_7) {
//   const char *src = "123456789";
//   const char *trim_chars = NULL;
//   ck_assert_str_eq(s21_trim(src, trim_chars), "123456789");
// }
// END_TEST

// START_TEST(trim_8) {
//   const char *src = NULL;
//   const char *trim_chars = "a";
//   ck_assert_ptr_null(s21_trim(src, trim_chars));
// }
// END_TEST

// START_TEST(trim_9) {
//   const char *src = NULL;
//   const char *trim_chars = NULL;
//   ck_assert_ptr_null(s21_trim(src, trim_chars));
// }
// END_TEST

// START_TEST(trim_10) {
//   const char *src = "aaaaaaaaa";
//   const char *trim_chars = "a";
//   ck_assert_str_eq(s21_trim(src, trim_chars), "");
// }
// END_TEST

// Suite *test_s21_trim(void) {
//   Suite *s13;
//   TCase *tc13;

//   s13 = suite_create("s21_trim");
//   tc13 = tcase_create("case_trim");

//   tcase_add_test(tc13, trim_1);
//   tcase_add_test(tc13, trim_2);
//   tcase_add_test(tc13, trim_3);
//   tcase_add_test(tc13, trim_4);
//   tcase_add_test(tc13, trim_5);
//   tcase_add_test(tc13, trim_6);
//   tcase_add_test(tc13, trim_7);
//   tcase_add_test(tc13, trim_8);
//   tcase_add_test(tc13, trim_9);
//   tcase_add_test(tc13, trim_10);

//   suite_add_tcase(s13, tc13);
//   return s13;
// }

// #include "../s21_string_tests.h"

START_TEST(s21_trim_1) {
  char s1[30] = "-?String project!";
  char s3[] = "!?-";
  char s4[] = "String project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_4) {
  char s1[30] = "-?String -!?!- project!";
  char s3[] = "!?-";
  char s4[] = "String -!?!- project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_5) {
  char s1[30] = "String project";
  char s3[] = "das";
  char s4[] = "String project";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_6) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_7) {
  char s1[] = " Test ";
  char *s3 = S21_NULL;
  char *s4 = "Test";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim_8) {
  char s1[] = " Test ";
  char *s3 = "";
  char *s4 = "Test";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *test_s21_trim(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("Core of s21_trim");
  /*Tests*/
  tcase_add_test(tc, s21_trim_1);
  tcase_add_test(tc, s21_trim_2);
  tcase_add_test(tc, s21_trim_3);
  tcase_add_test(tc, s21_trim_4);
  tcase_add_test(tc, s21_trim_5);
  tcase_add_test(tc, s21_trim_6);
  tcase_add_test(tc, s21_trim_7);
  tcase_add_test(tc, s21_trim_8);
  suite_add_tcase(s, tc);
  return s;
}

// int s21_trim_run_test(void) {
//   Suite *suite = s21_trim_create_suite();
//   SRunner *srunner = srunner_create(suite);
//   srunner_run_all(srunner, CK_NORMAL);
//   int failed_count = srunner_ntests_failed(srunner);
//   srunner_free(srunner);
//   if (failed_count != 0) {
//     return EXIT_FAILURE;
//   }
//   return EXIT_SUCCESS;
// }