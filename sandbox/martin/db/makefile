 #
# Makefile för att kompilera programmet test_db med g++
#

CCC = g++-4.7
CCFLAGS = -g -std=c++11  -pedantic -Wall -Wextra
LDFLAGS = -static-libstdc++

test_db: test_db.o Database.o sqlite3.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) test_db.o Database.o sqlite3.o -o test_db

Database.o: Database.cc Database.h
	$(CCC) $(CCFLAGS) -c Database.cc

test_db.o: test_db.cc
	$(CCC) $(CCFLAGS) -c test_db.cc

sqlite3.o: sqlite3.c sqlite3.h
	gcc -c sqlite3.c


clean:
	@ \rm -f *.o
	@ \rm -f *.~*~