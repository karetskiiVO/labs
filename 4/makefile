#the compiler
CC := g++
 
#flags:
CFLAGS := -g -Wall -Wextra #-fsanitize=address

#sources of input
SOURCES 	  := main.cpp security.cpp decryption.cpp enter.cpp verification.cpp 

#sources of output
EXECUTABLE := disp

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm