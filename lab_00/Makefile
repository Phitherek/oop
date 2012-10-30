CXX=clang++
CXXFLAGS=-Wall
test: main.o lista.o
	$(CXX) $(CXXFLAGS) -o test main.o lista.o
main.o: main.cpp
lista.o: lista.cpp
clean:
	rm -rf *.o test
check:
	./test
