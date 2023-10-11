# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++20 -g -O3

# Source files
SOURCES = head.cpp pwd.cpp tail.cpp tee.cpp wc.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Targets for executables
EXECUTABLES = head pwd tail tee wc

# compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# All executables
all: $(EXECUTABLES)

# Individual executable rules
$(EXECUTABLES): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)

.PHONY: all clean
