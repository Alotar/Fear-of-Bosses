CC=g++
CFLAGS=-Wall -c -g
LDFLAGS=
INCLDS=-I.

SOURCES:=$(wildcard *.cpp attributes/*.cpp network/*.cpp world/*.cpp \
                    world/entities/*.cpp world/items/*.cpp )

OBJECTS=$(SOURCES:.cpp=.o)

ALL = $(OBJECTS)

all: $(ALL)
	$(CC) $(LDFLAGS) $(OBJECTS) -o server

.cpp.o:
	$(CC) $(CFLAGS) $(INCLDS) $< -o $@

clean:
	find . -name \*.o -delete 
