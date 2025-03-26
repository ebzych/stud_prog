CFLAGS = -I headers
SOURCES = ./array_hashset_lib/*

ENTRY_POINT = ./entry_points

RELEASE_OUTPUT = ./Build/Release/'compare sets'
DEBUG_OUTPUT = ./Build/Debug/compare_sets
TESTING_OUTPUT = ./Build/Testing/test_compare_sets

Debug : ${SOURCES}
	gcc -g ${CFLAGS} ${SOURCES} ${ENTRY_POINT}/main.c -o ${DEBUG_OUTPUT}

Tests: ${SOURCES}
	gcc -g ${CFLAGS} ${SOURCES} ${ENTRY_POINT}/test_main.c -o ${TESTING_OUTPUT}

Release : ${SOURCES}
	gcc ${CFLAGS} ${SOURCES} ${ENTRY_POINT}/main.c -o ${RELEASE_OUTPUT} -O3