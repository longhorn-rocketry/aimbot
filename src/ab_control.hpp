#ifndef AIMBOT_AB_CONTROL_HPP
#define AIMBOT_AB_CONTROL_HPP

#include "bs_control.hpp"
#include "config.hpp"
#include "profiling.hpp"

namespace aimbot {

class AirbrakeController final {
private:
  const float m_BRAKE_POSITION_MIN = 0.0;
  const float m_BRAKE_POSITION_MAX = 1.0;

  AirbrakeControllerConfiguration m_config;
  BrakeStepController* m_step_controller;
  Profile* m_step_profile;
  float m_brake_position;

public:
  AirbrakeController(const AirbrakeControllerConfiguration& k_config);

  ~AirbrakeController();

  float get_brake_position();

  float update(float k_time,
               float k_velocity,
               float k_alt_min,
               float k_alt_max);
};

}; // end namespace aimbot

#endif
