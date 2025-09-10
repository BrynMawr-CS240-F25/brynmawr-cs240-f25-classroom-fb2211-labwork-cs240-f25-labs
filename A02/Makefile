CC=gcc
CSOURCES=$(wildcard *.c)
CEXES := $(subst .c,,$(CSOURCES))
FLAGS=-g -Wno-unused-variable -Wno-unused-but-set-variable

# By default, make runs the first target in the file
all: $(CEXES) 

% :: %.c 
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< -o $@ 

clean:
	rm -rf $(CEXES)

