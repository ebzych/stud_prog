CC = gcc
CFLAGS = -Og
LIB = -ICString -I "../../unity_tests/Unity/src" -I "../../unity_tests/Unity/extras/fixture/src" -I "../../unity_tests/Unity/extras/memory/src"
SOURCE = CString/*.c
OBJ = *.o

UNITY_TESTS = ../../unity_tests/Unity/src/unity.c
UNITY_FIXTURE = ../../unity_tests/Unity/extras/fixture/src/unity_fixture.c
UNITY_MEMORY = ../../unity_tests/Unity/extras/memory/src/unity_memory.c

clean:
	rm -rf $(OBJ)


debug: debug_build clean

debug_build:
	$(CC) $(CFLAGS) $(LIB) CString/*.c sources/*.c -lm -o build/Debug/debug_CString

test: test_build clean

test_build:
	$(CC) $(CFLAGS) $(LIB) CString/*.c tests/*.c \
		$(UNITY_TESTS) $(UNITY_MEMORY) $(UNITY_FIXTURE) -lm -o build/Test/test_CString
