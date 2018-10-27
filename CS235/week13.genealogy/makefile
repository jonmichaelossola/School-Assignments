###############################################################
# Program:
#     Week 13, Geneolagy
#     Brother Ercanbrack, CS235
# Author:
#	  Jon Michael Ossola
# Summary:
#     This program will complete a heap merge and merge sort 
#     on files filled with intergers.
# Time:
#     Probably around 15-20 hours.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: geneolagy.o
	g++ -o a.out geneolagy.o -g
	tar -cf week13.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week13.o     : the driver program
##############################################################
geneolagy.o: geneolagy.cpp list.h node.h level.cpp bnode.h
	g++ -c geneolagy.cpp -g
##############################################################
# Makes clean 
##############################################################
clean:
	rm a.out *.o *.tar

all : a.out
