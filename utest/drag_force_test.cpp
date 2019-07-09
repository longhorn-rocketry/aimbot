#include <CppUTest/TestHarness.h>
#include <string>

#include "drag_force.hpp"
#include "standard_atmosphere.hpp"
#include "testing_util.hpp"

#define PI 3.14159265359

using namespace aimbot;

TEST_GROUP(DragForceTest)
{
};

TEST(DragForceTest, SimpleDragForce)
{
  rocket_t rocket;
  rocket.mass = 35;
  rocket.radius = 0.0762;
  rocket.surface_area = PI * rocket.radius * rocket.radius;
  rocket.drag_coefficient = 0.46;

  state_t state;
  state.altitude = 1000;
  state.velocity = 250;

  float f = simple_drag_force(rocket, state);
  float f_exp = 291.589;

  CHECK_APPROX(f, f_exp);

  float a = simple_net_acceleration(rocket, state);
  float a_exp = -f_exp / rocket.mass - atmos::gravity_at(state.altitude);

  CHECK_APPROX(a, a_exp);
}
