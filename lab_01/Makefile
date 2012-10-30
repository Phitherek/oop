lifot: main.o lifo.o
	$(CXX) $(CXXFLAGS) -o lifot main.o lifo.o
main.o: main.cpp
lifo.o: lifo.cpp
clean:
	rm -rf *.o lifot
check:
	./lifot
