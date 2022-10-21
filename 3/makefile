#the compiler
CC := gcc
 
#flags:
CFLAGS := -g -Wall -Wextra -fsanitize=address

#sources of input
SOURCES := main.c  danger_identification.c  slope_finder.c  input.c

#sources of output
EXECUTABLE := corrector

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm