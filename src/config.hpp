#ifndef AIMBOT_CONFIG_HPP
#define AIMBOT_CONFIG_HPP

namespace aimbot {

typedef struct AirbrakeControllerConfiguration {
  float target_altitude;

  // Brake step profiler
  float bs_profile_step_min;
  float bs_profile_step_max;
  float bs_profile_velocity_min;
  float bs_profile_velocity_max;
  float bs_profile_exp;

  // Brake step controller general
  float bsc_thresh_oscillation;
  float bsc_thresh_stability;
  unsigned int bsc_error_history_size;

  // Brake step controller dampener
  float bsc_damp_profile_weight_min;
  float bsc_damp_profile_weight_max;
  float bsc_damp_profile_velocity_min;
  float bsc_damp_profile_velocity_max;
  float bsc_damp_profile_exp;

  // Brake step controller amplifier
  float bsc_amplify_profile_weight_min;
  float bsc_amplify_profile_weight_max;
  float bsc_amplify_profile_velocity_min;
  float bsc_amplify_profile_velocity_max;
  float bsc_amplify_profile_exp;
} abc_config_t;

} // end namespace aimbot

#endif
