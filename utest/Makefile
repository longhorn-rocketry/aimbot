make utest:
	g++ -std=c++11 unit_test_main.cpp -o utest.a -lCppUTest -I../src/            \
	atmos_test.cpp                                                               \
	drag_force_test.cpp                                                          \
	struct_util_test.cpp                                                         \
	cd_schedule_test.cpp                                                         \
	curve_gen_test.cpp                                                           \
	ab_control_test.cpp                                                          \
	cd_plane_test.cpp                                                            \
	testing_util.cpp                                                             \
	testing_util.hpp                                                             \
	torchy_cd_plane.hpp                                                          \
	../src/standard_atmosphere.cpp                                               \
	../src/standard_atmosphere.hpp                                               \
	../src/drag_force.cpp                                                        \
	../src/drag_force.hpp                                                        \
	../src/struct_util.cpp                                                       \
	../src/struct_util.hpp                                                       \
	../src/cd_profile.cpp                                                        \
	../src/cd_profile.hpp                                                        \
	../src/curve_generation.cpp                                                  \
	../src/curve_generation.hpp                                                  \
	../src/ab_control.cpp                                                        \
	../src/ab_control.hpp                                                        \
	../src/bs_control.cpp                                                        \
	../src/bs_control.hpp                                                        \
	../src/aimbot_util.cpp                                                       \
	../src/aimbot_util.hpp                                                       \
	../src/profiling.cpp                                                         \
	../src/profiling.hpp                                                         \
	../src/cd_plane.cpp                                                          \
	../src/cd_plane.hpp                                                          \
	../src/config.hpp

make clean:
	rm utest
