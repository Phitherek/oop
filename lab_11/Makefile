CXXFLAGS=-Wall
all:
	${CXX} ${CXXFLAGS} -o ptest ptest.cpp ParsingUtils.cpp
debug:
	${CXX} ${CXXFLAGS} -o ptest ptest.cpp ParsingUtils.cpp -g
clean:
	rm -rf ptest
check:
	./ptest
