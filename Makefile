CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized

BINARIES= WordCount, tests





WordCount: WordCount.cpp WordCount.h
	g++ WordCount.cpp -o WordCount


tests: tests.cpp WordCount.cpp WordCount.h
	g++ tests.cpp WordCount.cpp -o tests


clean:
	/bin/rm -f ${BINARIES} *.o
