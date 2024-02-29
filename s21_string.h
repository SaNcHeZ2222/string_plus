#ifndef S21_STRING_H_
#define S21_STRING_H_

// #include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// typedef unsigned long long s21_s21_size_t;
#define S21_NULL ((void *)0)
#define SIZE 40
#define s21_size_t unsigned long long

// http://microsin.net/programming/arm/void-type-in-c-language.html гайд про
// void * https://pvs-studio.com/ru/blog/terms/0088/ про терминирующий 0
// http://natalia.appmat.ru/c&c++/lezione5.php обо всем по чуть-чуть

int s21_sprintf(char *buf, const char *str_format, ...);
int s21_sscanf(const char *str, const char *format, ...);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delimiters);
char *s21_strchr(const char *str, int c);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
s21_size_t s21_strspn(const char *str1, const char *str2);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);

// Бонус
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
#endif  // S21_STRING_H_
