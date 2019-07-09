make unit_test:
	g++ -std=c++11 unit_test_main.cpp -o unit_test -lCppUTest -I../src/          \
	atmos_test.cpp                                                               \
	drag_force_test.cpp                                                          \
	struct_util_test.cpp                                                         \
	cd_schedule_test.cpp                                                         \
	testing_util.cpp                                                             \
	testing_util.hpp                                                             \
	../src/standard_atmosphere.cpp                                               \
	../src/standard_atmosphere.hpp                                               \
	../src/drag_force.cpp                                                        \
	../src/drag_force.hpp                                                        \
	../src/struct_util.cpp                                                       \
	../src/struct_util.hpp                                                       \
	../src/cd_schedule.cpp                                                       \
	../src/cd_schedule.hpp

make clean:
	rm unit_test
