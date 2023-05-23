CC = g++
CFLAG = -Wall -Wextra -Werror
UNAME:= $(shell uname -s)

ifeq ($(UNAME), Linux)
OPEN_CMD = xdg-open
ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
leaks_util := valgrind --leak-check=full
endif
ifeq ($(UNAME), Darwin)
OPEN_CMD = open
leaks_util := CK_FORK=no leaks --atExit --
endif

all: install

install: clean
	cp -r view/* build
	cd build; qmake; make;
	cp -r  ./build/3DViewer.app .

uninstall: clean
	rm -rf ./view/view.app

dvi: 
	$(OPEN_CMD) dvi.html
	
dist: install
	@rm -rf 3DViewer.tar.gz
	tar -czvf 3DViewer.tar.gz 3DViewer.app dvi.html
	@rm -rf 3DViewer.app

tests: clean
	$(CC) -lgtest ./tests/main.cc ./model/*.cpp -o ./tests/test
	cd tests; $(leaks_util) ./test

check:
	@cp -f ../materials/linters/clang-format clang-format
	@cp -f ../materials/linters/suppression.cfg suppression.cfg
	clang-format -i ./view/*.cpp ./view/*.h ./model/* ./controller/*
	clang-format -n ./view/*.cpp ./view/*.h ./model/* ./controller/*
	cppcheck --language=c++ --enable=all --suppressions-list=suppression.cfg ./view/*.cpp ./view/*.h ./model/* ./controller/*

clean:
	@rm -rf *.o *.gcda *.gcno *.info clang-format suppression.cfg
	@rm -rf ./build/*
	@rm -rf ./build_tests/*
	@rm -rf 3DViewer.tar.gz
	@rm -rf 3DViewer.app
	@rm -rf 3DViewer
	@rm -f suppression.cfg
	@rm -f clang-format
	@rm -f ./tests/test

rebuild: clean all
