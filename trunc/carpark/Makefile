#
# FILENAMN:      Makefile
# PROJECT:       A3B
# PROGRAMMERARE: Conny Andersson    910124-2411 Y3a conan414@student.liu.se
#                Andreas Bolin      820406-2098 Y3a andbo467@student.liu.se
#                Martin Andersson   890929-0566 Y3a maran703@student.liu.se
#                Adam Andersson                 Y3a adaan690@student.liu.se
# DATE:          2012-11-09
#
# DESCRIPTION 
# 
# Compiling with "make"
# Run with "run"
#
#

BACKEND = ../backend
DATABASE = ../database
GUI = ../gui

GCC = gcc
CXX = g++
#CXX = gccfilter -c -a g++

# Flaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I$(BACKEND) -I$(DATABASE) -I$(GUI)

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = bilpark.o Carpark.o GUI.o Database.o Reservation.o Search_reservation.o Vehicle.o Search_vehicle.o Settings.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
main: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o run $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
bilpark.o: bilpark.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c bilpark.cc

Carpark.o: Carpark.h Carpark.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c Carpark.cc

GUI.o: $(GUI)/GUI.h $(GUI)/GUI.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(GUI)/GUI.cc

Database.o: $(DATABASE)/Database.h $(DATABASE)/Database.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(DATABASE)/Database.cc

Reservation.o: $(BACKEND)/Reservation.h $(BACKEND)/Reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Reservation.cc

Search_reservation.o: $(BACKEND)/Search_reservation.h $(BACKEND)/Search_reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Search_reservation.cc

Vehicle.o: $(BACKEND)/Vehicle.h $(BACKEND)/Vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Vehicle.cc

Vehicle.o: $(BACKEND)/Search_vehicle.h $(BACKEND)/Search_vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Search_vehicle.cc

Vehicle.o: $(BACKEND)/Settings.h $(BACKEND)/Settings.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND)/Settings.cc

sqlite3.o: sqlite.h sqlite.c
	$(GCC) -c $(DATABASE)/sqlite.c

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o run *~

clean-win:
	@ rm -rf *.o *.gch run.exe *~
