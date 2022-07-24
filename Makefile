all: run

run: test
	./test.exe

.PHONY: all run

test: main.cpp ArbitraryPrecisionFloat.cpp ArbitraryPrecisionFloat.h
	g++ -w -o test.exe main.cpp ArbitraryPrecisionFloat.cpp ArbitraryPrecisionFloat.h