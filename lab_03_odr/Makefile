CXXFLAGS = -Wall
htest:
	$(CXX) $(CXXFLAGS) -o htest htest.cpp Hist.cpp
clean:
	rm -rf *.o htest
check:
	./htest
debug:
	$(CXX) $(CXXFLAGS) -o htest htest.cpp Hist.cpp -g
