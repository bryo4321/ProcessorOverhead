CC=/usr/bin/g++
CFLAGS= -g -Wall -I. -std=c++14
LINKFLAGS= -g -Wall

all:experiment

experiment:main.o DefaultClock.o
	$(CC) $(LINKFLAGS) -o experiment main.o DefaultClock.o

main.o:main.cpp DefaultClock.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

DefaultClock.o:DefaultClock.cpp DefaultClock.h
	$(CC) $(CFLAGS) -c DefaultClock.cpp -o DefaultClock.o

clean:
	rm -f *.o experiment
