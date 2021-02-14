# uncomment the line below and change the compiler flags if you need to
# CXXFLAGS = -std=c++11 

all: 
	g++ Phase1Main.cpp $(CXXFLAGS) -o Phase1
	g++ LazyMainTest.cpp $(CXXFLAGS) -o Lazy
main:
	g++ Phase1Main.cpp $(CXXFLAGS) -o Phase1
lazy:
	g++ LazyMainTest.cpp $(CXXFLAGS) -o Lazy
