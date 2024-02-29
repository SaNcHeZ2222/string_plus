#include "../s21_string.h"

char *s21_strtok(char *str, const char *delimiters) {
  static char *lastToken = NULL;
  if (str != NULL) {
    lastToken = str;
  } else {
    if (lastToken == NULL || *lastToken == '\0') {
      return NULL;
    }
  }
  char *tokenStart = lastToken;
  while (*tokenStart != '\0' &&
         s21_strchr(delimiters, *tokenStart) != NULL) {  // s21_strchr
    tokenStart++;
  }
  if (*tokenStart == '\0') {
    lastToken = NULL;
    return NULL;
  }
  char *tokenEnd = tokenStart + 1;
  while (*tokenEnd != '\0' &&
         s21_strchr(delimiters, *tokenEnd) == NULL) {  // s21_strchr
    tokenEnd++;
  }
  if (*tokenEnd == '\0') {
    lastToken = NULL;
  } else {
    *tokenEnd = '\0';
    lastToken = tokenEnd + 1;
  }
  return tokenStart;
}