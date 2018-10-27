###############################################################
# Program:
#     Project 09, Skeet
#     Brother Macbeth, CS165
# Author:
#     Jon Michael Ossola
# Summary:
#     The code runs and plays the game of skeet.
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o standardBird.o toughBird.o sacredBird.o bird.o bullet.o flyingObject.o velocity.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o standardBird.o toughBird.o sacredBird.o bird.o bullet.o flyingObject.o velocity.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h toughBird.h sacredBird.h toughBird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp 
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
standardBird.o: standardBird.cpp standardBird.h bird.h flyingObject.h 
	g++ -c standardBird.cpp

toughBird.o: toughBird.cpp toughBird.h bird.h flyingObject.h 
	g++ -c toughBird.cpp

sacredBird.o: sacredBird.cpp sacredBird.h flyingObject.h 
	g++ -c sacredBird.cpp

bird.o: bird.cpp bird.h flyingObject.cpp flyingObject.h
	g++ -c bird.cpp

bullet.o: bullet.cpp bullet.h flyingObject.cpp flyingObject.h
	g++ -c bullet.cpp

flyingObject.o: flyingObject.cpp flyingObject.h
	g++ -c flyingObject.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
