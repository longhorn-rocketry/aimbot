#include <CppUTest/TestHarness.h>
#include <math.h>

#include "standard_atmosphere.hpp"

using namespace aimbot;

namespace {
  bool approx(float a, float b) {
    return fabs(a - b) < 0.01;
  }
}

TEST_GROUP(StandardAtmosphereTest)
{
};

TEST(StandardAtmosphereTest, TemperatureAtAltitude)
{
  float f = atmos::temperature_at(-1000);
  CHECK_EQUAL(atmos::ATMOS_ERROR, f);

  f = atmos::temperature_at(20000);
  CHECK_EQUAL(atmos::ATMOS_ERROR, f);

  f = atmos::temperature_at(0);
  if (!approx(f, 15))
    FAIL("Interpolation failure");

  f = atmos::temperature_at(5000);
  if (!approx(f, -17.47))
    FAIL("Interpolation failure");

  f = atmos::temperature_at(10000);
  if (!approx(f, -49.9))
    FAIL("Interpolation failure");

  f = atmos::temperature_at(2500);
  if (!approx(f, (2.0 + -4.49) / 2))
    FAIL("Interpolation failure");

  f = atmos::temperature_at(7333);
  if (!approx(f, -30.45 + (-36.94 - -30.45) / 3))
    FAIL("Interpolation failure");
}

TEST(StandardAtmosphereTest, AirDensityAt)
{
  float f = atmos::air_density_at(-1000);
  CHECK_EQUAL(atmos::ATMOS_ERROR, f);

  f = atmos::air_density_at(20000);
  CHECK_EQUAL(atmos::ATMOS_ERROR, f);

  f = atmos::air_density_at(0);
  if (!approx(f, 1.225))
    FAIL("Interpolation failure");

  f = atmos::air_density_at(5000);
  if (!approx(f, 0.7364))
    FAIL("Interpolation failure");

  f = atmos::air_density_at(10000);
  if (!approx(f, 0.4135))
    FAIL("Interpolation failure");

  f = atmos::air_density_at(2500);
  if (!approx(f, (1.007 + 0.9093) / 2))
    FAIL("Interpolation failure");

  f = atmos::air_density_at(7333);
  if (!approx(f, 0.59 + (0.5258 - 0.59) / 3))
    FAIL("Interpolation failure");
}
