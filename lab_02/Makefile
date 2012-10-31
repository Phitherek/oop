tabtest: main.o tab.o
	$(CXX) $(CXXFLAGS) -o tabtest main.o tab.o
main.o: main.cpp
tab.o: tab.cpp
clean:
	rm -rf *.o tabtest
check:
	./tabtest
debug:
	$(CXX) $(CXXFLAGS) -o tabtest main.cpp tab.cpp -g
