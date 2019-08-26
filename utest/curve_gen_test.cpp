// #include <CppUTest/TestHarness.h>
// #include <iostream>
//
// #include "curve_generation.hpp"
// #include "testing_util.hpp"
//
// #define PI 3.14159265359
//
// using namespace aimbot;
//
// TEST_GROUP(CurveGeneration)
// {
// };
//
// TEST(CurveGeneration, ScheduledEulerGeneration)
// {
//   const cdpoint_t ROCKET_CD_SCHED_POINTS[] = {
//     {0.46, 0},
//     {0.55, 0.5},
//     {0.67, 0.9},
//     {0.91, 1.0},
//     {0.76, 1.1},
//     {0.55, 1.4},
//     {0.23, 2.0}
//   };
//   const cdpoint_t AIRBRAKE_CD_SCHED_POINTS[] = {
//     {1.28, 0}
//   };
//
//   CdSchedule rocket_cd_sched(ROCKET_CD_SCHED_POINTS, 7);
//   CdSchedule airbrake_cd_sched(AIRBRAKE_CD_SCHED_POINTS, 1);
//
//   cgen::set_timestep(0.01);
//   cgen::set_rocket_cd_schedule(&rocket_cd_sched);
//   cgen::set_airbrake_cd_schedule(&airbrake_cd_sched);
//
//   rocket_t rocket;
//   rocket.mass = 35;
//   rocket.radius = 0.0762;
//   rocket.surface_area = PI * rocket.radius * rocket.radius;
//
//   state_t state;
//   state.altitude = 250;
//   state.velocity = 320;
//
//   cgen::bounds_t bounds = cgen::integrate_euler(rocket, state);
//
//   if (bounds.lower < 0 || bounds.upper < 0 || bounds.lower > bounds.upper ||
//       bounds.lower < state.altitude)
//     FAIL("Illogical bounds");
// }
