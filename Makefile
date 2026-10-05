CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

wordscanner: wordscanner.cc
	$(CXX) $(CXXFLAGS) wordscanner.cc -o wordscanner

clean:
	rm -f wordscanner