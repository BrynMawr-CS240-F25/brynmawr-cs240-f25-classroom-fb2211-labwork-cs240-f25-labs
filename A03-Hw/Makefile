CC=g++
CSOURCES=$(wildcard common/*.c common/*.h)
CEXES=test_gates test_alu test_memory test_computer test_cpu hackdb hacksim test_cpu test_cpu_instructions
FLAGS=-g -Wno-unused-variable -Wno-unused-but-set-variable
INCLUDE_DIR=-I. -I./common
LIB_DIR=

# By default, make runs the first target in the file
all: $(CEXES) 

% :: %.c $(CSOURCES)
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< $(CSOURCES) -o $@ -lncurses -lreadline

hacksim :: hacksim.c $(CSOURCES)
	$(CC) $(FLAGS) $(INCLUDE_DIR) -DFAST_RAM $(LIB_DIR) -Wl,-rpath=. $< $(CSOURCES) -o $@ -lX11

clean:
	rm -rf $(CEXES)

