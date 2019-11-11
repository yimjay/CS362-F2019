# Student: Ji Soo Yim
# Description: Makefile for testme.c

CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = testme

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.cpp .o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
