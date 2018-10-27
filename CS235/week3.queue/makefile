###############################################################
# Program:
#     Week 03, QUEUE
#     Brother Ercanbrack, CS235
# Author:
#     Jon Michael Ossola
# Summary:
#     Queue project: contains a queue data structure with implementation
#     as well as demonstrates its use with stocks.
# Time:
#     Probably around 13 hours.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h week03.o dollars.o stock.o
	g++ -o a.out week03.o dollars.o stock.o -g
	tar -cf week03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp -g

##############################################################
# The individual components
#      week03.o       : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
week03.o: queue.h week03.cpp
	g++ -c week03.cpp -g 

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp -g

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp -g

clean:
	rm *.o a.out