EXENAME = main
# OBJS = main.o Graph.o
OBJS = main.o utility.o Graph.o tarjan.o
OBJS_DIR = .objs

CXX = clang++
CXXFLAGS = -std=c++20 -c -gdwarf-4 -g -O0 -Wall -Wextra 
LD = clang++
LDFLAGS = -std=c++20

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

Graph.o: Graph.cpp Graph.h
	$(CXX) $< $(CXXFLAGS)

utility.o: utility.cpp utility.h
	$(CXX) $< $(CXXFLAGS)

tarjan.o: tarjan.cpp tarjan.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)