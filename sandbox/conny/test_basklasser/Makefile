#
# FILENAMN:   Makefile
# PROJECT:    Test  -  backend
# PROGRAMMER: Conny Andersson  Y3a conan414@student.liu.se
#             Andreas Bolin    Y3a andbo467@student.liu.se
#             Martin Andersson Y3a maran703@student.liu.se
#             Adam Andersson   Y3a adaan690@student.liu.se
# DATE:       2012-11-18
#
# DESCRIPTION 
# 
# Compiling with "make"
# Run with "run"
#

BACKEND = ../backend
DATABASE = ../database

# Kompilatorer
GCC = gcc
CXX = g++
#CXX = gccfilter -c -a g++

# Flaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I$(BACKEND) -I$(DATABASE) #-I$(GUI)

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ingår i den kompletta bilparken.
OBJECTS = test_basklasser.o Reservation.o Search_reservation.o Vehicle.o Search_vehicle.o Settings.o Database.o sqlite3.o 

#////////////////////////////////////////////////////////////////////
#/ Huvudfunktion:
#/  Huvudmål - skapas med kommandot 'make' eller 'make main'.
#////////////////////////////////////////////////////////////////////
main: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o run $(OBJECTS)

#////////////////////////////////////////////////////////////////////
#/ Testfunktioner:
#/  Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
#////////////////////////////////////////////////////////////////////

test_basklasser.o: test_basklasser.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c test_basklasser.cc

test_db.o: test_db.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c test_db.cc

#////////////////////////////////////////////////////////////////////
#/ backend:
#////////////////////////////////////////////////////////////////////
Reservation.o: $(BACKEND)/Reservation.h $(BACKEND)/Reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Reservation.cc

Search_reservation.o: $(BACKEND)/Search_reservation.h $(BACKEND)/Search_reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Search_reservation.cc

Vehicle.o: $(BACKEND)/Vehicle.h $(BACKEND)/Vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Vehicle.cc

Search_vehicle.o: $(BACKEND)/Search_vehicle.h $(BACKEND)/Search_vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Search_vehicle.cc

Settings.o: $(BACKEND)/Settings.h $(BACKEND)/Settings.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Settings.cc

#////////////////////////////////////////////////////////////////////
#/ database:
#////////////////////////////////////////////////////////////////////
Database.o: $(DATABASE)/Database.cc $(DATABASE)/Database.h
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(DATABASE)/Database.cc

sqlite3.o: $(DATABASE)/sqlite3.c $(DATABASE)/sqlite3.h
	$(GCC) -c $(DATABASE)/sqlite3.c

#////////////////////////////////////////////////////////////////////
#/ clean:
#/  'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
#////////////////////////////////////////////////////////////////////
clean:
	@ \rm -rf *.o run *~ core

clean-win:
	@ rm -rf *.o *.gch run.exe *~
