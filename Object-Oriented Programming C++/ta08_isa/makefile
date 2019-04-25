# Main executable
a.out: circle.o point.o ta08.o
	g++ circle.o point.o ta08.o

point.o: point.cpp point.h
	g++ -c point.cpp

circle.o: circle.cpp circle.h point.h
	g++ -c circle.cpp

ta08.o: ta08.cpp circle.h
	g++ -c ta08.cpp

