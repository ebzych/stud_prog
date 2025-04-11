CC = gcc
LIBS = -I ~/Documents/stud_prog/unity_tests/Unity/src -I lib
CFLAGS = -g

SOURCES = sources/*.c
OBJ = init_console.o compsets.o

RELEASE_OUTPUT = 
DEBUG_OUTPUT = Build/Debug/compare_sets
TEST_OUTPUT = Build/Test/test_init_array

UNIT_TESTS = ~/Documents/stud_prog/unity_tests/Unity/src/unity.c

clean: all
	rm -rf compsets.o init_console.o

all: init_console.o compsets.o
	$(CC) $(CFLAGS) $(LIBS) $(SOURCES) $(OBJ) -lm -o $(DEBUG_OUTPUT)

inconsole.o: lib/init_console.c
	$(CC) $(CFLAGS) $(LIBS) lib/init_console.c -lm -c

compsets.o: lib/compsets.c
	$(CC) $(CFLAGS) $(LIBS) lib/compsets.c -lm -c

test:
	$(CC) $(CFLAGS) $(LIBS) tests/test_input.c \
		lib/init_console.c $(UNIT_TESTS) -lm -o $(TEST_OUTPUT)
