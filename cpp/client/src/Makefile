CC=g++
CFLAGS=-Wall -c -g
LDFLAGS=
INCLDS=-I.

SOURCES:=$(wildcard *.cpp network/*.cpp interface/*.cpp)

OBJECTS=$(SOURCES:.cpp=.o)

ALL = $(OBJECTS)

all: $(ALL)
	$(CC) $(LDFLAGS) $(OBJECTS) -o client

.cpp.o:
	$(CC) $(CFLAGS) $(INCLDS) $< -o $@

clean:
	find . -name \*.o -delete 
