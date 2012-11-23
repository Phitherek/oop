all:
	g++ -o otest otest.cpp Opt.cpp ShortOpt.cpp LongOpt.cpp Arg.cpp ShortOptWithArg.cpp
debug:
	g++ -o otest otest.cpp Opt.cpp ShortOpt.cpp LongOpt.cpp Arg.cpp ShortOptWithArg.cpp -g
clean:
	rm -rf otest
check:
	./otest
