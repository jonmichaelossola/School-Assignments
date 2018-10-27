###############################################################
# Program:
#     Checkpoint 08b, More inheritance
#     Brother Macbeth, CS165
# Author:
#     Jon Michael Ossola
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : phone.o smartphone.o check08b.o
	g++ phone.o smartphone.o check08b.o

phone.o : phone.h phone.cpp
	g++ -c phone.cpp

smartphone.o : smartphone.h phone.h smartphone.cpp
	g++ -c smartphone.cpp

check08b.o : smartphone.h phone.h check08b.cpp
	g++ -c check08b.cpp

clean :
	rm *.o a.out

