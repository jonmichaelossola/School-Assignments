###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Macbeth, CS165
# Author:
#     Jon Michael Ossola
# Summary:
#     Summaries are not necessary for checkpoint assignments.
###############################################################


# Insert your rule for a.out here:
a.out : robot.o point.o check06a.o
	g++ robot.o point.o check06a.o

# Insert your rule for robot.o here:
robot.o : robot.cpp robot.h check06a.cpp
	g++ -c robot.cpp

# Insert your rule for point.o here:
point.o : point.h point.cpp check06a.cpp
	g++ -c point.cpp

# Insert your rule for check06a.o here:
check06a.o : check06a.cpp
	g++ -c check06a.cpp