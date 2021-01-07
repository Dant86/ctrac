CC=g++
SDIR=src/sets
CFLAGS=-std=c++11

ctrac: driver.o sets.o
	$(CC) -o driver driver.o sets.o $(CFLAGS)

driver.o: src/driver.cpp $(SDIR)/sets.h
	$(CC) -c src/driver.cpp $(CFLAGS)

sets.o: $(SDIR)/sets.cpp $(SDIR)/sets.h
	$(CC) -c $(SDIR)/sets.cpp $(SDIR)/sets.h $(CFLAGS)
