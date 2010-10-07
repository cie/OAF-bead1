CPP=g++
CPPFLAGS=-ansi -pedantic -g

run_test: test/runner
	./test/runner

test/runner: test/runner.cpp test/test.h bignum.h bignum.cpp 
	cd test && ${CPP} ${CPPFLAGS} -idirafter ../cxxtest   runner.cpp  ../bignum.cpp -o runner

test/runner.cpp: test/test.h 
	cd test && python ../cxxtest/python/scripts/cxxtestgen --error-printer test.h -o runner.cpp 


