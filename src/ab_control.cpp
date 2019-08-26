#include "ab_control.hpp"
#include "aimbot_util.hpp"

namespace aimbot {

AirbrakeController::AirbrakeController(const abc_config_t& k_config) {
  m_config = k_config;
  m_brake_position = 0;
  m_step_profile = new BinomialProfile(
    k_config.bs_profile_velocity_min,
    k_config.bs_profile_velocity_max,
    k_config.bs_profile_step_min,
    k_config.bs_profile_step_max,
    k_config.bs_profile_exp
  );
  m_step_controller = new BrakeStepController(k_config);
}

AirbrakeController::~AirbrakeController() {
  delete m_step_profile;
}

float AirbrakeController::get_brake_position() {
  return m_brake_position;
}

float AirbrakeController::update(float k_time,
                                 float k_velocity,
                                 float k_alt_min,
                                 float k_alt_max)
{
  float midpoint = k_alt_min + (k_alt_max - k_alt_min) / 2;
  float error = midpoint - m_config.target_altitude;
  float base_step = m_step_profile->get(k_velocity);

  // Apply step control for oscillation reduction
  m_brake_position += m_step_controller->update(base_step, error, k_velocity)
                      * util::sign(error);

  // Clamp to allowed range
  m_brake_position = util::clamp(
    m_BRAKE_POSITION_MIN,
    m_BRAKE_POSITION_MAX,
    m_brake_position
  );

  return m_brake_position;
}

}; // end namespace aimbot
