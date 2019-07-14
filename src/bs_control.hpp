#ifndef AIMBOT_BS_CONTROL_HPP
#define AIMBOT_BS_CONTROL_HPP

#include "config.hpp"
#include "profiling.hpp"

namespace aimbot {

class BrakeStepController final {
private:
  const unsigned int mERROR_HISTORY_SIZE;
  const float mTHRESH_OSCILLATION;
  const float mTHRESH_STABILITY;

  BinomialProfile* m_profile_damp;
  BinomialProfile* m_profile_amplify;

  unsigned int m_iterations;
  float* m_error_history;
  float m_weight;

public:
  BrakeStepController(const abc_config_t& k_config);

  ~BrakeStepController();

  float update(float k_step_size, float k_altitude_error, float k_velocity);

  float get_weight() const;

  void set_weight(float k_weight);
};

}; // end namespace aimbot

#endif
