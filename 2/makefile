#the compiler
CC := g++
 
#flags:
CFLAGS := -g -Wall -Wextra -fsanitize=address

#sources of input
SOURCES := main.cpp Experiment.cpp  Computing.cpp  Analys.cpp

#sources of output
EXECUTABLE := corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm