# Student: Ji Soo Yim
# Description: Makefile for testme.c

CXX = g++
CXXFLAGS = -std=c99 -Wall -fpic -coverage -lm
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
