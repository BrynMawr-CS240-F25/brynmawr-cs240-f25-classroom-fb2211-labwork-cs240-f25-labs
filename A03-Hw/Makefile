CC=g++
CSOURCES=$(wildcard common/*.c common/*.h)
CEXES=test_gates test_alu test_memory
FLAGS=-g -Wno-unused-variable -Wno-unused-but-set-variable
INCLUDE_DIR=-I. -I./common
LIB_DIR=

# By default, make runs the first target in the file
all: $(CEXES) 

test_gates :: test_gates.c $(CSOURCES)
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< $(CSOURCES) -o $@ -lncurses -lreadline

test_alu :: test_alu.c $(CSOURCES)
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< $(CSOURCES) -o $@ -lncurses -lreadline

test_memory :: test_memory.c $(CSOURCES)
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< $(CSOURCES) -o $@ -lncurses -lreadline

clean:
	rm -rf $(CEXES)

