OPT=Nic
CXXFLAGS=-Wall -D$(OPT)
all:
	$(CXX) $(CXXFLAGS) -o mtest mtest.cpp
debug:
	$(CXX) $(CXXFLAGS) -o mtest mtest.cpp -g
clean:
	rm -rf mtest
check:
	./mtest
