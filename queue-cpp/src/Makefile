
CXXFLAGS := -g -std=c++17 -Wmissing-declarations -Wall -Wextra -MMD -fPIC -D_GNU_SOURCE


EXEC = main

all: $(EXEC)

main: main.cpp 

clean:
	rm -f *.o $(EXEC)

format:
	clang-format -i *.h *.cpp
