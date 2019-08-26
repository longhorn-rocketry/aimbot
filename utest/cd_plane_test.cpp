#include <CppUTest/TestHarness.h>
#include <iostream>

#include "cd_plane.hpp"
#include "testing_util.hpp"
#include "torchy_cd_plane.hpp"

using namespace aimbot;

TEST_GROUP(CdPlane)
{
};

TEST(CdPlane, PlaneInterpolation)
{
  cd_plane_t hyp;
  hyp.plane = TORCHY_CD_PLANE;
  hyp.alt_low = 0;
  hyp.alt_high = 5000;
  hyp.alt_step = 100;
  hyp.vel_low = 0;
  hyp.vel_high = 2.0 * 343;
  hyp.vel_step = 5;

  float cd = cd_at(hyp, 2500, 3);
  std::cout << cd << std::endl;
}
