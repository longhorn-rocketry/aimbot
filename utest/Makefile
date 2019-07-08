make unit_test:
	g++ -std=c++11 unit_test_main.cpp -o unit_test -lCppUTest -I../src/          \
	atmos_test.cpp                                                               \
	drag_force_test.cpp                                                          \
	testing_util.cpp                                                             \
	testing_util.hpp                                                             \
	../src/standard_atmosphere.cpp                                               \
	../src/standard_atmosphere.hpp                                               \
	../src/drag_force.cpp                                                        \
	../src/drag_force.hpp

make clean:
	rm unit_test
