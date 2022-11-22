#the compiler
CC := g++
 
#flags:
CFLAGS := -g -Wall -Wextra #-fsanitize=address

#sources of input
SOURCES_DEBUG := deb.cpp security.cpp decryption.cpp enter.cpp verification.cpp 
SOURCES 	  := deb.cpp security.cpp decryption.cpp enter.cpp verification.cpp 

#sources of output
EXECUTABLE := disp

all:
	$(CC) $(SOURCES) $(CFLAGS) -MD -o $(EXECUTABLE) -lm

debug:
	$(CC) $(SOURCES_DEBUG) $(CFLAGS) -MD -o $(EXECUTABLE) -lm