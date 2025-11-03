CC=g++
COMMON=$(wildcard common/*.cpp)
CSOURCES=$(wildcard *.cpp)
CEXES := $(subst .cpp,,$(CSOURCES))
FLAGS=-g -Wno-unused-variable -Wno-unused-but-set-variable -Icommon

# By default, make runs the first target in the file
all: $(CEXES) 

% :: %.cpp $(COMMON)
	$(CC) $(FLAGS) $(INCLUDE_DIR) $(LIB_DIR) -Wl,-rpath=. $< $(COMMON) -o $@ 

clean:
	rm -rf $(CEXES) *.o

