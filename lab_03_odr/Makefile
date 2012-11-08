CXXFLAGS = -Wall
htest: htest.o Hist.o
	$(CXX) $(CXXFLAGS) -o htest htest.o Hist.o
htest.o: htest.cpp
Hist.o: Hist.cpp
clean:
	rm -rf *.o htest
check:
	./htest
debug:
	$(CXX) $(CXXFLAGS) -o htest htest.cpp Hist.cpp -g
