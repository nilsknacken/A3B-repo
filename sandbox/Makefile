GCC = gcc
CXX = g++
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

OBJECTS = test.o

main: $(OBJECTS) Makefile
	$(CXX) $(CCFLAGS) $(LDFLAGS) -o run $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
test.o: test.cc
	$(CXX) $(CCFLAGS) -c test.cc

sqlite3.o: sqlite.h sqlite.c
	$(GCC) -c sqlite.c

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o run *~ core

clean-win:
	@ rm -rf *.o *.gch run.exe *~
