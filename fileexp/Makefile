//Roll no - 2018201088
//Name 	  - Anant Rawat
//Course  - M.Tech CSE 1st year
CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = headers.h
OBJ = working.o work.cpp
%.o: %.cpp $(DEPS)
				$(CC) $(CFLAGS) -c -o $@ $<

filexp: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^
