all: run

run: test
	./test.exe

.PHONY: all run

test: main.cpp ArbitraryPrecisionFloat.cpp ArbitraryPrecisionFloat.h ByteArrayConverter.cpp ByteArrayConverter.h
	g++ -w -o test.exe main.cpp ArbitraryPrecisionFloat.cpp ArbitraryPrecisionFloat.h ByteArrayConverter.h ByteArrayConverter.cpp 