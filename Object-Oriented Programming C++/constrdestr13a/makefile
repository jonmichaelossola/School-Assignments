###############################################################
# Program:
#     Checkpoint 13a, Destructors
#     Brother Macbeth, CS165
# Author:
#     Jon Michael Ossola
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : numberList.o check13a.o
	g++ numberList.o check13a.o

numberList.o : numberList.h numberList.cpp
	g++ -c numberList.cpp

check13a.o : numberList.h check13a.cpp
	g++ -c check13a.cpp

clean :
	rm *.o *.out
