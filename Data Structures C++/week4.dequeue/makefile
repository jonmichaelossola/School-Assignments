###############################################################
# Program:
#     Week 04, DEQUE
#     Brother ercanbrack, CS235
# Author:
#     Jon Michael Ossola
# Summary:
#     The following includes the deque class, along with
#	  the implementation of it in the CS lab.
# Time:
#     Probably a total of 5 hours. It was great! 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h week04.o nowServing.o
	g++ -o a.out week04.o nowServing.o -g
	tar -cf week04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week04.o       : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
week04.o: deque.h week04.cpp
	g++ -c week04.cpp -g

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -g

clean:
	rm a.out *.o

testBed:
	testBed cs235e/week04 week04.tar