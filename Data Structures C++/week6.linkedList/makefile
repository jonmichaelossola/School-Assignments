###############################################################
# Program:
#     Week 06, NODE
#     Brother Ercanbrack, CS235
# Author:
#     Jon Michael Ossola
# Summary:
#     This is the node class, along with the sort implementation.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h week06.o 
	g++ -o a.out week06.o  -g
	tar -cf week06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week06.o      : the driver program
#      <anything else?>
##############################################################
week06.o: node.h week06.cpp sortInsertion.h
	g++ -c week06.cpp -g
