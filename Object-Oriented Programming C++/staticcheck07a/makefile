###############################################################
# Program:
#     Checkpoint 07a, Static
#     Brother Macbeth, CS165
# Author:
#     Jon Michael Ossola
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


a.out : icecream.o check07a.o
	g++ icecream.o check07a.o

icecream.o : icecream.h icecream.cpp
	g++ -c icecream.cpp

check07a.o : icecream.h check07a.cpp
	g++ -c check07a.cpp

clean :
	rm *.o
	rm a.out
