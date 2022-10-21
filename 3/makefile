#the compiler
CC := gcc
 
#flags:
CFLAGS := -g -Wall -Wextra -fsanitize=address

#sources of input
SOURCES := main.cpp  danger_identification.cpp  slope_finder.cpp  input.cpp

#sources of output
EXECUTABLE := corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm