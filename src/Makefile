TESTS_DIR := ./TEST
C_SRCS := $(wildcard ./*.c)
C_OBJS := $(C_SRCS:%.c=%.o)

all: clean my_decimal.a

my_decimal.a: $(C_OBJS)
	ar rcs ./$@ $^
	ranlib my_decimal.a
	make clean_object_file

%.o: %.c
	gcc -c -std=c11 -g -Wall -Werror -Wextra $< -o $@

test: clean my_decimal.a $(TESTS_DIR)/my_test_decimal.c
	gcc -std=c11 -Wall -Werror -Wextra $(TESTS_DIR)/*.c -o $(TESTS_DIR)/test.o -L. my_decimal.a -lcheck -lsubunit -lm
	$(TESTS_DIR)/test.o

gcov_report: clean my_decimal.a
	gcc -fprofile-arcs -ftest-coverage -Wall -Werror -Wextra -std=c11  ./*.c $(TESTS_DIR)/*.c -o a.o -L. my_decimal.a -lcheck -lsubunit -lm
	./a.o
	gcov -f $(C_SRCS)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	firefox report/index.html
	make clean

clang_n:
	cp ../materials/linters/.clang-format ../src
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n $(TESTS_DIR)/*.c
	clang-format -n $(TESTS_DIR)/*.h
	make clean_clang

clang_i:
	cp ../materials/linters/.clang-format ../src
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i $(TESTS_DIR)/*.c
	clang-format -i $(TESTS_DIR)/*.h
	make clean_clang

valgrind: clean my_decimal.a
	gcc -std=c11 -Wall -Werror -Wextra *.c $(TESTS_DIR)/*.c -o $(TESTS_DIR)/test.o -L. my_decimal.a -lcheck -lsubunit -lm
	$(TESTS_DIR)/test.o
	valgrind --tool=memcheck --leak-check=yes $(TESTS_DIR)/test.o
	make clean

clean_object_file:
	rm -rf *.o

clean_clang:
	rm -rf .clang-format

clean:
	rm -rf *.o ./*/*.o *.a
	rm -rf *.gcno *.gcda *.info report.out *.gcov
	rm -rf report


