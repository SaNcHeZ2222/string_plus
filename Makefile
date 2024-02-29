CC = gcc
# CC= gcc -arch x86_64 #for MacBook with M processor
CFLAGS = -Wall -Wextra -Werror -std=c11
STRING = ./functions/*.c
#STRING = ./functions/s21_*.c 
OBJECTS = *.o
TEST= ./tests/*.c
#TEST = ./tests/s21_*.c ./tests/test_s21_*.c
TEST_FLAGS = -lcheck -lpthread -lm
CLANG = clang-format -style=Google

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
  TEST_FLAGS += -lsubunit -lrt
endif

.PHONY: all clean test rebuild

all: clean s21_string.a test gcov_report

s21_string.a: 
	$(CC) $(CFLAGS) -c  $(STRING)
	ar rcs s21_string.a $(OBJECTS)

test: s21_string.a
	$(CC) $(CFLAGS) $(STRING) $(TEST) s21_string.a $(TEST_FLAGS) -o test
	./test

rebuild:
	make clean
	make all

clean: 
	rm -rf *.o *.a *.out test *.gch *.gcno *.gcda *.info report 

# brew:
#  curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
#  brew install lcov

gcov_report: s21_string.a
	$(CC) $(CFLAGS) --coverage $(STRING) $(TEST) $(TEST_FLAGS) -lm -o test 
	./test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	open report/index.html
	rm -rf *.o *.a  *.gch *.gcno test *.gcda


clang-n:
	$(CLANG) -n *.[ch] 
	$(CLANG) -n ./functions/*.[ch]
	$(CLANG) -n ./tests/*.[ch]

clang-i:
	$(CLANG) -i *.[ch] 
	$(CLANG) -i ./functions/*.[ch]
	$(CLANG) -i ./tests/*.[ch]
