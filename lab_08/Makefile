all:
	g++ -o otest otest.cpp Opt.cpp ShortOpt.cpp LongOpt.cpp Arg.cpp ShortOptWithArg.cpp Options.cpp
debug:
	g++ -o otest otest.cpp Opt.cpp ShortOpt.cpp LongOpt.cpp Arg.cpp ShortOptWithArg.cpp Options.cpp -g
clean:
	rm -rf otest
check:
	./otest
