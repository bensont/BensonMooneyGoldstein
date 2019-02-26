CXX = g++
CXXFLAGS = -Wall -g

all: test

test: tool.o simulation.o store.o customers.o rental.o timecounter.o rentalFactory.o
	g++ -o test tool.o simulation.o store.o rental.o timecounter.o rentalFactory.o

tool.o: tool.cpp tool.h
	g++ -c tool.cpp

simulation.o: simulation.cpp timecounter.o
	g++ -c simulation.cpp

store.o: store.cpp tool.h
	g++ -c store.cpp

rental.o: rental.cpp tool.h
	g++ -c rental.cpp

customers.o: customers.cpp rental.h
	g++ -c customers.cpp

timecounter.o: timecounter.cpp
	g++ -c timecounter.cpp

rentalFactory.o: rentalFactory.cpp store.h
	g++ -c rentalFactory.cpp