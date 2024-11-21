# Compiler and flags
CC=g++
CFLAGS=-std=c++17 -Wall -g

# The source files
ALL_SRC=$(wildcard *.cpp)

# The name of the resulting executable
APP=test

# Default target
custom_tests: main.cpp poly.cpp
	$(CC) $(CFLAGS) main.cpp poly.cpp -o $(APP)

# Clean up build artifacts
clean:
	rm -f $(APP)
