AssocTest: AssocTest.o AssocArray.o
	$(CXX) $(CXXFLAGS) -o AssocTest AssocTest.o AssocArray.o
AssocTest.o: AssocTest.cpp
AssocArray.o: AssocArray.cpp
clean:
	rm -rf *.o AssocTest
check:
	./AssocTest
debug:
	$(CXX) -o AssocTest AssocTest.cpp AssocArray.cpp -g
