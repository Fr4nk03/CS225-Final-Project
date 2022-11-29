EXENAME = main
# OBJS = main.o Graph.o
OBJS = main.o utility.o Graph.o 
OBJS_DIR = .objs

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

Graph.o: Graph.cpp Graph.h
	$(CXX) $< $(CXXFLAGS)

utility.o: utility.cpp utility.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)