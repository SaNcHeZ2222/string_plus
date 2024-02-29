#include <check.h>
#include <string.h>

#include "../s21_string.h"

// START_TEST(test_1) {
//   char str[] = "Hello, world!";
//   char buf1[100];
//   s21_sprintf(buf1, str);
//   char buf2[100];
//   sprintf(buf2, str);
//   ck_assert_pstr_eq(buf1, buf2);
// }

START_TEST(test_2) {
  char str[] = "Hello, %-10hd world!";
  char buf1[100];
  s21_sprintf(buf1, str, -17);
  char buf2[100];
  sprintf(buf2, str, -17);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_3) {
  char str1[] = "Hello, %+2hu world!";
  char buf1[100];
  int val1 = 1784531;
  s21_sprintf(buf1, str1, val1);
  char buf2[100];
  sprintf(buf2, str1, val1);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_4) {
  char str[500] = "qwd% 40ddty";  //%+10.2ld
  int val = -2523454;
  char buf2[1000];
  s21_sprintf(buf2, str, val);
  char buf1[1000];
  sprintf(buf1, str, val);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_5) {
  char str[500] = "%-25.25f";  //%+10.2ld
  int val1 = -2523454;
  double val2 = 123.135227132321234;
  unsigned int val3 = 1234892133;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_6) {
  char str[500] = "qwd% 40hddtyf%10s!%-25.25f%20hu";  //%+10.2ld
  int val1 = -2523454;
  double val2 = 123.135227132321234;
  unsigned int val3 = 1234892133;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_7) {
  char str[500] = "qwd% 40hddtyf%10s!%-25.25Lf%20hu!!!%X";  //%+10.2ld
  int val1 = -2523454;
  long double val2 = 123.135227132321234;
  unsigned int val3 = 12348133;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_8) {
  char str[500] = "qwd% 40hddtyf%10s!%-25.10E%+20hu!!!%o";  //%+10.2ld
  int val1 = -2523454;
  double val2 = 94e+7;
  unsigned int val3 = -123481;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_9) {
  char str[500] = "qwd% 40hddtyf%10s!%-25.10e%20hu!!!%x";  //%+10.2ld
  int val1 = -2523454;
  double val2 = -94e+7;
  unsigned int val3 = -123481;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_10) {
  char str[500] = "qwr%3.0fre%10s";  //%+10.2ld
  double val1 = 199.924;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_11) {
  char str[500] = "qwr%3.1fre%10s";  //%+10.2ld
  double val1 = -199.524;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_12) {
  char str[500] = "qwd%+40lddtyf%10s!%-25.10e%20hu!!!%lx";  //%+10.2ld
  int val1 = -2523454;
  double val2 = -94e+7;
  unsigned int val3 = -123481;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_13) {
  char str[500] = "qwd%+40ludtyf%10s!%-25.10e%20hu!!!%hx";  //%+10.2ld
  int val1 = -2523454;
  double val2 = -1.943e-8;
  unsigned int val3 = -123481;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_14) {
  char str[500] = "!!%p";  //%+10.2ld
  // double x = 1.0;
  char *p = "123";
  char buf2[1000];
  s21_sprintf(buf2, str, p);
  char buf1[1000];
  sprintf(buf1, str, p);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_15) {
  char str[500] = "qwd%#Xddtyf%10s!%025.10E%+20hu!!!%#o";  //%+10.2ld
  int val1 = -2523454;
  double val2 = 94e+7;
  unsigned int val3 = -123481;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ", val2, val3, val3);
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ", val2, val3, val3);
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(testG_1) {
  char str[500] = "qwr  %3.3g  re%10s";  //%+10.2ld
  double val1 = -100.51;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(testG_4) {
  char str[500] = "qwr  %3.7g  re%10s";  //%+10.2ld
  double val1 = 12345.67;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(testG_5) {
  char str[500] = "qwr  %3.6g  re%10s";  //%+10.2ld
  double val1 = 12345.6;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(testG_6) {
  char str[500] = "qwr  %3.7g  re%10s";  //%+10.2ld
  double val1 = 123450101.80066;
  char buf2[1000];
  s21_sprintf(buf2, str, val1, "QQQ");
  char buf1[1000];
  sprintf(buf1, str, val1, "QQQ");
  ck_assert_pstr_eq(buf1, buf2);
}
END_TEST

START_TEST(test_20) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%*s><%-*s><%*.*s><%.*s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_21) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%u><%u><%u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_22) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%lu><%lu><%hu><%hu>";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_23) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3u><%5u><%10u>";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_24) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5u><%.23u><%3.u><%.u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_25) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+u><%+3.u><%+5.7u><%+10u>";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_26) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%u><%3.u><%5.7u><%10u><%#u><%-u><%+u><%.u><% .u>";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_27) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<% u><% 3.u><% 5.7u><% 10u><%.u>";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_28) {
  char str1[200];
  char str2[200];
  char *str3 = "<%#s><%#3s><%#5.7s><%#.7s Oof %#.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_29) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "<%20.E>|<%-20.E>";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_30) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "<% 30.1E>|<% 30.E>|<%030.0E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_31) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<%- 17.1E>|<% -17.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_32) {
  char str1[300] = "";
  char str2[300] = "";
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "<%# 10.2E>|<% #10.0E>|<%010.E>";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_33) {
  char str1[600] = "";
  char str2[600] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<% 10.1E>|<%- 10.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_34) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%.e>|<%.2e>|<%.5E>|<%.9E>|<%.13E>";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_35) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%e>|<%.e>|<%.5e>|<%.9e>|<%.15E>";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_36) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%060Le!>|<%.14Le>";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_37) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%4f>|<%4.f>|<%5.10f>";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_38) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%3f>|<%4.f>|<%5.10f>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_39) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_40) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%5f>|<%6.1f>|<%8.2f>";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_41) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %o %n  %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

START_TEST(test_42) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%o><%o><%o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_43) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%lo><%lo><%ho><%ho>";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_44) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%3o><%5o><%10o>";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_45) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%6.5o><%.23o><%3.o><%.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_46) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5o><%-.8o><%-7o><%-.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_47) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0o><%0.o><%0.0o><%0o><%.o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_48) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+o><%+3.o><%+5.7o><%+10o>";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_49) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%o><%3.o><%5.7o><%10o %#o %-o %+o %.o % .o>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_50) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%+o><%+3.o><%+5.7o><%+10o><%+.o>";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(test_51) {
//   char str1[200] = "";
//   char str2[200] = "";
//   char *str3 = "<%s><%3.s><%5.7s><%10s %#s %-s %+s %.s % .s>";
//   char *val = NULL;
//   ck_assert_int_eq(
//       sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
//       s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
//   ck_assert_pstr_eq(str1, str2);
// }
END_TEST

START_TEST(test_52) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%0s><%0.s><%0.0s><%0s GOD %.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_53) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%-10.5s><%-.8s><%-7s><%-.s>";
  char *val = "WHAT IS THIS>";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_54) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%ls>";
  wchar_t *val = L"3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_s21_sprintf() {
  Suite *s = suite_create("sprintf");

  TCase *tc_1 = tcase_create("specifiers_tests");
  // tcase_add_test(tc_1, test_1);
  tcase_add_test(tc_1, test_2);
  tcase_add_test(tc_1, test_3);
  tcase_add_test(tc_1, test_4);
  tcase_add_test(tc_1, test_5);
  tcase_add_test(tc_1, test_6);
  tcase_add_test(tc_1, test_7);
  tcase_add_test(tc_1, test_8);
  tcase_add_test(tc_1, test_9);
  tcase_add_test(tc_1, test_10);
  tcase_add_test(tc_1, test_11);
  tcase_add_test(tc_1, test_12);
  tcase_add_test(tc_1, test_13);
  tcase_add_test(tc_1, test_14);
  tcase_add_test(tc_1, test_15);
  tcase_add_test(tc_1, test_20);
  tcase_add_test(tc_1, test_21);
  tcase_add_test(tc_1, test_22);
  tcase_add_test(tc_1, test_23);
  tcase_add_test(tc_1, test_24);
  tcase_add_test(tc_1, test_25);
  tcase_add_test(tc_1, test_26);
  tcase_add_test(tc_1, test_27);
  tcase_add_test(tc_1, test_28);
  tcase_add_test(tc_1, test_29);
  tcase_add_test(tc_1, test_30);
  tcase_add_test(tc_1, test_31);
  tcase_add_test(tc_1, test_32);
  tcase_add_test(tc_1, test_33);
  tcase_add_test(tc_1, test_34);
  tcase_add_test(tc_1, test_35);
  tcase_add_test(tc_1, test_36);
  tcase_add_test(tc_1, test_37);
  tcase_add_test(tc_1, test_38);
  tcase_add_test(tc_1, test_39);
  tcase_add_test(tc_1, test_40);
  tcase_add_test(tc_1, test_41);
  tcase_add_test(tc_1, test_42);
  tcase_add_test(tc_1, test_43);
  tcase_add_test(tc_1, test_44);
  tcase_add_test(tc_1, test_45);
  tcase_add_test(tc_1, test_46);
  tcase_add_test(tc_1, test_47);
  tcase_add_test(tc_1, test_48);
  tcase_add_test(tc_1, test_49);
  tcase_add_test(tc_1, test_50);
  // tcase_add_test(tc_1, test_51);
  tcase_add_test(tc_1, test_52);
  tcase_add_test(tc_1, test_53);
  tcase_add_test(tc_1, test_54);

  suite_add_tcase(s, tc_1);

  TCase *tc_specifier_G = tcase_create("specifiers_tests_G");
  tcase_add_test(tc_specifier_G, testG_1);
  tcase_add_test(tc_specifier_G, testG_4);
  tcase_add_test(tc_specifier_G, testG_5);
  tcase_add_test(tc_specifier_G, testG_6);
  suite_add_tcase(s, tc_specifier_G);
  return s;
}
