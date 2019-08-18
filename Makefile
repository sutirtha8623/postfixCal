CXX = g++
CXXFLAGS = -c -Wall -g
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

$(info SRCS = $(SRCS)) 

%.o:%.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@ 
	
calc:$(OBJS)
	$(CXX) -o $@ $^
	
clean:
	rm -f $(OBJS) calc *~
