#include <CppUTest/TestHarness.h>
#include <iostream>

#include "ab_control.hpp"
#include "bs_control.hpp"
#include "testing_util.hpp"

using namespace aimbot;

TEST_GROUP(AirbrakeControl)
{
};

TEST(AirbrakeControl, BrakeStepControl)
{
  abc_config_t config;
  config.bsc_thresh_oscillation = 0.7;
  config.bsc_thresh_stability = 0.2;
  config.bsc_error_history_size = 4;

  config.bsc_damp_profile_weight_min = 0.1;
  config.bsc_damp_profile_weight_max = 0.3;
  config.bsc_damp_profile_velocity_min = 40;
  config.bsc_damp_profile_velocity_max = 250;
  config.bsc_damp_profile_exp = -1;

  config.bsc_amplify_profile_weight_min = 0.1;
  config.bsc_amplify_profile_weight_max = 0.3;
  config.bsc_amplify_profile_velocity_min = 40;
  config.bsc_amplify_profile_velocity_max = 250;
  config.bsc_amplify_profile_exp = -1;

  BrakeStepController bsc(config);
  bsc.update(0, 1, 0);
  bsc.update(0, -2, 0);
  bsc.update(0, 4, 0);
  bsc.update(0, -1, 0);

  float step = 0.3;
  float step_mod = bsc.update(step, 2, 100);

  if (step_mod >= step)
    FAIL("Illogical brake step control");

  bsc.set_weight(0.5);

  for (int i = 0; i < 10; i++)
    bsc.update(0, 3, 0);

  float w = bsc.get_weight();

  if (w <= 0.5)
    FAIL("Illogical brake step control");
}
