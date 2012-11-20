#
# FILENAMN:   Makefile
# PROJECT:    A3B
# PROGRAMMER: Conny Andersson  Y3a conan414@student.liu.se
#             Andreas Bolin    Y3a andbo467@student.liu.se
#             Martin Andersson Y3a maran703@student.liu.se
#             Adam Andersson   Y3a adaan690@student.liu.se
# DATE:       2012-11-20
#
# DESCRIPTION 
# 
# Compiling with "make"
# Run with "run"
#

BACKEND_DIR = ../backend
DATABASE_DIR = ../database
GUI_DIR = ../gui
CARPARK_DIR = ../carpark

CC = gcc
#CXX = g++
CXX = gccfilter -c -a g++
MAKE = make
QMAKE = qmake

# Flaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++11 -pedantic -Wall -Wextra
QTFLAGS += -Wall

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I$(BACKEND_DIR) -I$(DATABASE_DIR) -I$(GUI_DIR)

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L/sw/gcc-$(GCC4_V)/lib -static-libstdc++

# Objektkodsmoduler som ingår i den kompletta bilparken.
BACKEND_OBJECTS = bilpark.o Carpark.o Reservation.o Search_reservation.o Vehicle.o Search_vehicle.o Settings.o
DB_OBJECTS = Database.o sqlite3.o
FRONTEND_OBJECTS = Gui.o
OBJECTS = $(BACKEND_OBJECTS) $(DB_OBJECTS) $(FRONTEND_OBJECTS)


########################################################
# Huvudmål - skapas med kommandot 'make' eller 'make main'.
main: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o run $(OBJECTS)

########################################################
# Backend
########################################################
# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
bilpark.o: $(CARPARK_DIR)/bilpark.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(CARPARK_DIR)/bilpark.cc

Carpark.o: $(CARPARK_DIR)/Carpark.h $(CARPARK_DIR)/Carpark.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(CARPARK_DIR)/Carpark.cc

Reservation.o: $(BACKEND_DIR)/Reservation.h $(BACKEND_DIR)/Reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND_DIR)/Reservation.cc

Search_reservation.o: $(BACKEND_DIR)/Search_reservation.h $(BACKEND_DIR)/Search_reservation.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND_DIR)/Search_reservation.cc

Vehicle.o: $(BACKEND_DIR)/Vehicle.h $(BACKEND_DIR)/Vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND_DIR)/Vehicle.cc

Search_Vehicle.o: $(BACKEND_DIR)/Search_vehicle.h $(BACKEND_DIR)/Search_vehicle.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND_DIR)/Search_vehicle.cc

Settings.o: $(BACKEND_DIR)/Settings.h $(BACKEND_DIR)/Settings.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(BACKEND_DIR)/Settings.cc

########################################################
# Database
########################################################
Database.o: $(DATABASE_DIR)/Database.h $(DATABASE_DIR)/Database.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c $(DATABASE_DIR)/Database.cc

sqlite3.o: $(DATABASE_DIR)/sqlite.h $(DATABASE_DIR)/sqlite.c
	$(CC) -c $(DATABASE_DIR)/sqlite.c

########################################################
# GUI
########################################################
Gui.o: $(GUI_DIR)/Gui.h $(GUI_DIR)/Gui.cc
	cd $(GUI_DIR); $(QMAKE) -project -o Gui.pro
	cd $(GUI_DIR); $(QMAKE) -makefile $(QTFLAGS) -o Makefile Gui.pro #$(QTFLAGS) funkar inte, behöver (kanske) lägga till den!
	cd $(GUI_DIR); $(MAKE) -f Makefile

########################################################
# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o run
	@ \rm -rf *~ core
	@ \rm -rf $(GUI_DIR)/Makefile
	@ \rm -rf $(GUI_DIR)/*.pro

clean-gui:
	@ \rm -rf Gui.o
	@ \rm -rf $(GUI_DIR)/Makefile
	@ \rm -rf $(GUI_DIR)/*.pro

clean-win:
	@ rm -rf *.o *.gch run.exe *~
	@ rm -rf $(GUI_DIR)/Makefile
	@ rm -rf $(GUI_DIR)/*.pro
