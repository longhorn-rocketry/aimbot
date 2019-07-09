#include <CppUTest/TestHarness.h>

#include "standard_atmosphere.hpp"
#include "testing_util.hpp"

TEST_GROUP(StandardAtmosphereTest)
{
};

TEST(StandardAtmosphereTest, TemperatureAtAltitude)
{
  float f = atmos::temperature_at(0);
  CHECK_APPROX(f, 15);

  f = atmos::temperature_at(5000);
  CHECK_APPROX(f, -17.47);

  f = atmos::temperature_at(10000);
  CHECK_APPROX(f, -49.9);

  f = atmos::temperature_at(2500);
  CHECK_APPROX(f, (2.0 + -4.49) / 2);

  f = atmos::temperature_at(7333);
  CHECK_APPROX(f, -30.45 + (-36.94 - -30.45) / 3);
}

TEST(StandardAtmosphereTest, AirDensityAt)
{
  float f = atmos::air_density_at(0);
  CHECK_APPROX(f, 1.225);

  f = atmos::air_density_at(5000);
  CHECK_APPROX(f, 0.7364);

  f = atmos::air_density_at(10000);
  CHECK_APPROX(f, 0.4135);

  f = atmos::air_density_at(2500);
  CHECK_APPROX(f, (1.007 + 0.9093) / 2);

  f = atmos::air_density_at(7333);
  CHECK_APPROX(f, 0.59 + (0.5258 - 0.59) / 3);
}
