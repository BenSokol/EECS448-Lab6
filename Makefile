#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o LinkedListTests.o
	g++ -g -Wall -std=c++11 main.o LinkedListOfInts.o LinkedListTests.o -o prog

main.o: main.cpp LinkedListTests.cpp LinkedListTests.hpp
	g++ -g -Wall -std=c++11 -c main.cpp

LinkedListTests.o: LinkedListTests.cpp LinkedListTests.hpp
	g++ -g -Wall -std=c++11 -c LinkedListTests.cpp

#DON'T delete LinkedList.o!
clean:
	rm main.o LinkedListTests.o *.*~ prog
