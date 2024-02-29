#include "s21_string_test.h"

int main() {
  int failed = 0;

  Suite *s21_string_tests[] = {test_s21_strncpy(),  test_s21_strlen(),
                               test_s21_strncmp(),  test_s21_strcspn(),
                               test_s21_to_lower(), test_s21_to_upper(),
                               test_s21_memcp(),    test_s21_strpbrk(),
                               test_s21_strrchr(),  test_s21_strtok(),
                               test_s21_trim(),     test_s21_memset(),
                               test_s21_strerror(), test_s21_insert(),
                               test_s21_strchr(),   test_s21_strncat(),
                               test_s21_strstr(),   test_s21_memcpy(),
                               test_s21_memchr(),   test_s21_sprintf(),
                               test_s21_sscanf(),   NULL};
  for (int i = 0; s21_string_tests[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_string_tests[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("________________    FAILED: %d    ________________\n", failed);
  return failed == 0 ? 0 : 1;
}
