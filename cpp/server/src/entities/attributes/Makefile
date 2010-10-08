CC     = g++ -g3 --ggdb
CCOPT  = -Wall -fstack-protector-all
INCLS  = -I. -I.. -I../.. -I../../..
CFLAGS = $(CCOPT) $(DEFS) $(INCLS)
LIBS   = 

.cpp.o:
  @rm -f $@
  $(CC) $(CFLAGS) -c $*.cpp -o $@
  
SRC_CORE = $(wildcard *.cpp)
OBJ_CORE = $(SRC_CORE:.cpp=.o)

ALL = $(OBJ_CORE)

all: $(ALL)
  
$(SERVER_NAME): $(OBJ_CORE)
  $(CC) $(CFLAGS) $(LDFLAGS) -o $(SERVER_NAME) $(OBJ_CORE) $(LIBS)

clean:
  rm -f $(OBJ_CORE)
