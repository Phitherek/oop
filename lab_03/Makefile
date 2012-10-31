ctest: ctest.o Charges.o
	$(CXX) $(CXXFLAGS) -o ctest ctest.o Charges.o
ctest.o: ctest.cpp
Charges.o: Charges.cpp
clean:
	rm -rf *.o ctest
check:
	./ctest
debug:
	$(CXX) $(CXXFLAGS) -o ctest ctest.cpp Charges.cpp -g
