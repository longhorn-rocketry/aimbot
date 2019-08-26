// #include <CppUTest/TestHarness.h>
// #include <iostream>
//
// #include "cd_profile.hpp"
// #include "testing_util.hpp"
//
// using namespace aimbot;
//
// TEST_GROUP(CdSchedule)
// {
// };
//
// TEST(CdSchedule, CdSchedule)
// {
//   const cd_event_t ARR[] = {
//     {0.46, 0},
//     {0.55, 0.5},
//     {0.67, 0.9},
//     {0.91, 1.0},
//     {0.76, 1.1},
//     {0.55, 1.4},
//     {0.23, 2.0}
//   };
//
//   CdSchedule sched(ARR, 7);
//
//   float f = sched.get_cd(0);
//   CHECK_APPROX(0.46, f);
//
//   f = sched.get_cd(0.95);
//   CHECK_APPROX((0.67 + 0.91) / 2, f);
//
//   f = sched.get_cd(-1);
//   CHECK_APPROX(0.46, f);
//
//   f = sched.get_cd(3.0);
//   CHECK_APPROX(0.23, f);
// }
