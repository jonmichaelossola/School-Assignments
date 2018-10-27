#######################
# Makefile for TA 13
#######################

a.out : ta13.o course.o student.o
	g++ ta13.o course.o student.o

ta13.o : ta13.cpp course.h student.h
	g++ -c ta13.cpp

course.o : course.cpp course.h student.h
	g++ -c course.cpp

student.o : student.cpp student.h
	g++ -c student.cpp

clean :
	rm a.out *.o
