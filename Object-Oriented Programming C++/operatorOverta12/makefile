###########################
# Builds Team Activity 12
###########################

a.out : velocity.o point.o ta12.o
	g++ velocity.o point.o ta12.o

velocity.o : velocity.h velocity.cpp
	g++ -c velocity.cpp

point.o : point.h point.cpp
	g++ -c point.cpp

ta12.o : point.h velocity.h ta12.cpp
	g++ -c ta12.cpp

clean :
	rm *.o a.out

