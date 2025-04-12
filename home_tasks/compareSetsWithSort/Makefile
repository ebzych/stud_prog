CC = gcc
LIBS = -I ~/Documents/stud_prog/unity_tests/Unity/src -I lib
CFLAGS = -g

SOURCES = sources/*.c
OBJ = arrays.o parsing_from_console.o init_array.o compsets.o

RELEASE_OUTPUT = 
DEBUG_OUTPUT = Build/Debug/compare_sets
TEST_OUTPUT = Build/Test/test_init_array

UNIT_TESTS = ~/Documents/stud_prog/unity_tests/Unity/src/unity.c

clean: all
	rm -rf $(OBJ)

all: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) $(SOURCES) -lm -o $(DEBUG_OUTPUT)

compsets.o: lib/compsets.c
	$(CC) $(CFLAGS) $(LIBS) lib/compsets.c -lm -c

init_array.o: lib/arrays.c lib/init_array.c
	$(CC) $(CFLAGS) $(LIBS) lib/arrays.c lib/init_array.c -lm -c

parsing_from_console.o: lib/init_array.c lib/parsing_from_console.c
	$(CC) $(CFLAGS) $(LIBS) lib/init_array.c lib/parsing_from_console.c -lm -c

arrays.o: lib/arrays.c
	$(CC) $(CFLAGS) $(LIBS) lib/arrays.c -lm -c

test:
	$(CC) $(CFLAGS) $(LIBS) tests/test_input.c \
		lib/compsets.c lib/init_array.c lib/parsing_from_console.c \
		lib/arrays.c $(UNIT_TESTS) -lm -o $(TEST_OUTPUT)
