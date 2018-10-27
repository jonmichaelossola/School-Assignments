###############################################################
# UiTest program
###############################################################

a.out : uiDraw.o uiInteract.o point.o uiTest.cpp 
	g++ -o a.out uiTest.cpp uiDraw.o uiInteract.o point.o -lglut -lGLU -lGL

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

###############################################################
# General rules
###############################################################
clean :
	rm *.out *.o *.tar *~

all :  a.out 

