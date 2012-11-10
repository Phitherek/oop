$CXXFLAGS=-Wall
all:
	$(CXX) $(CXXFLAGS) -o atest atest.cpp Angle.cpp
debug:
	$(CXX) $(CXXFLAGS) -o atest atest.cpp Angle.cpp -g
clean:
	rm -rf atest
check:
	./atest
