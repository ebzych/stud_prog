CC = gcc
CFLAGS = -g -O0
LIB = -ICString -I "../../unity_tests/Unity/src" -I "../../unity_tests/Unity/extras/fixture/src" -I "../../unity_tests/Unity/extras/memory/src"
SRC = CString/initiator_string.c CString/strcmp.c \
	CString/support_functions.c CString/big_strings.c CString/strcat.c \
	CString/strsub.c CString/strsep.c CString/strlrchr.c
OBJ = $(SRC:.c=.o)

UNITY_TESTS = ../../unity_tests/Unity/src/unity.c
UNITY_FIXTURE = ../../unity_tests/Unity/extras/fixture/src/unity_fixture.c
UNITY_MEMORY = ../../unity_tests/Unity/extras/memory/src/unity_memory.c

clean:
	rm -rf $(OBJ)

debug: debug_build clean

debug_build: $(OBJ)
	$(CC) $(CFLAGS) $(LIB) $(OBJ) sources/main.c -lm -o build/Debug/debug_CString

test: test_build clean

test_build: $(OBJ)
	$(CC) $(CFLAGS) $(LIB) $(SRC) tests/*.c \
		$(UNITY_TESTS) $(UNITY_MEMORY) $(UNITY_FIXTURE) -lm -o build/Test/test_CString

$(OBJ): %.o : %.c
	$(CC) -r $(CFLAGS) $(LIB) $< -o $@
