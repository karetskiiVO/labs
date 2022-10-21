#the compiler
CC := g++
 
#flags:
CFLAGS := -g -Wall -Wextra -fsanitize=address

#sources of input
SOURCES := main.cpp  danger_identification.cpp  slope_finder.cpp  input.cpp  output.cpp

#sources of output
EXECUTABLE := disp

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm