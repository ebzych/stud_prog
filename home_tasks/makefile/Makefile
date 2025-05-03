CC = gcc

DBG_FLAGS = -g -O0
RLS_FLAGS = -O3
LIBS = 
CFLAGS = 

SOURCES = int_arithm_lib/int_arithm.c
OBJECTS = $(SOURCES:.c=.o)

DEBUG_PATH = build/Debug/debug_lib
RELEASE_PATH =

.PHONY = all clean debug release

all: debug

clean:
	rm -rf int_arithm_lib/*.o

debug: $(OBJECTS)
	$(CC) $(DBG_FLAGS) $(LIBS) $(CFLAGS) -o $(DEBUG_PATH) $(OBJECTS)

release: $(OBJECTS)
	$(CC) $(RLS_FLAGS) $(LIBS) $(CFLAGS) $(OBJECTS) -o $(RELEASE_PATH)

$(OBJECTS) : %.o : %.c
	$(CC) -r -c $(DBG_FLAGS) $(LIBS) $(CFLAGS) $< -o $@