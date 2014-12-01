all:single_basic single_medium

single_basic: single_number_basic.o
	g++ -o single_basic single_number_basic.o

single_number_basic.o: single_number_basic.cpp
	g++ -c -Wall single_number_basic.cpp

single_medium: single_number_medium.o
	g++ -o single_medium single_number_medium.o

single_number_medium.o: single_number_medium.cpp
	g++ -c -Wall single_number_medium.cpp

clean:
	rm single_basic single_medium *.o
