CXX = g++
CXXFLAGS = -Wall -g

all: test

test: tool.o simulation.o store.o customers.o rental.o timecounter.o rentalFactory.o customerFactory.o logger.o rentalList.o
	g++ -o test tool.o simulation.o store.o customers.o rental.o timecounter.o rentalFactory.o customerFactory.o logger.o rentalList.o

tool.o: tool.cpp
	g++ -c tool.cpp

simulation.o: simulation.cpp timecounter.o customers.h customerFactory.h tool.h store.h rentalFactory.o
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

customerFactory.o : customerFactory.cpp customers.o
	g++ -c customerFactory.cpp

logger.o: logger.cpp
	g++ -c logger.cpp
<<<<<<< HEAD

rentalList.o: rentalList.cpp tool.h
	g++ -c rentalList.cpp
=======
>>>>>>> 783fc71c85dcf2bbee5d7fbec8883859ebd55261
