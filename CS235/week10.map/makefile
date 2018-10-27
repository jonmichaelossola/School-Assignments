###############################################################
# Program:
#     Week 10, Map
#     Brother Ercanbrack, CS235
# Author:
#     Jon Michael Ossola
# Summary:
#     Includes the map and application of so.
# Time:
#     About two hours. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: map.o
	g++ -o a.out map.o 
	tar -cf week10.tar map.cpp makefile

##############################################################
# The individual components
#      lesson08.o     : the driver program
##############################################################
map.o: map.cpp
	g++ -c map.cpp -g

clean :
	rm *.o a.out

test :
	testBed cs235e/week10 week10.tar