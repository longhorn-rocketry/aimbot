#include <CppUTest/TestHarness.h>
#include <string>

#include "drag_force.hpp"
#include "testing_util.hpp"

#define PI 3.14159265359

using namespace aimbot;

TEST_GROUP(DragForceTest)
{
};

TEST(DragForceTest, SimpleDragForce)
{
  rocket_t rocket;
  rocket.radius = 0.0762;
  rocket.surface_area = PI * rocket.radius * rocket.radius;
  rocket.drag_coefficient = 0.46;

  state_t state;
  state.altitude = 1000;
  state.velocity = 250;

  float f = simple_drag_force(rocket, state);
  float f_exp = 291.589;

  if (!util::approx(f, f_exp))
    NOT_APPROX(f, f_exp);
}
