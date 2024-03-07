CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY: all
all: program

program: max-priority_queue.o
	$(CXX) $(CXXFLAGS) -o $@ $^

max-priority_queue.o: max-priority_queue.cpp
	$(CXX) $(CXXFLAGS) -c $<
.PHONY: clean
clean:
	rm *.o 
	rm program