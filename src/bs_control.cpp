#include "aimbot_util.hpp"
#include "bs_control.hpp"

namespace aimbot {

BrakeStepController::BrakeStepController(const abc_config_t& k_config) :
  mERROR_HISTORY_SIZE(k_config.bsc_error_history_size),
  mTHRESH_OSCILLATION(k_config.bsc_thresh_oscillation),
  mTHRESH_STABILITY(k_config.bsc_thresh_stability)
{
  m_iterations = 0;
  m_error_history = new float[mERROR_HISTORY_SIZE];
  m_profile_damp = new BinomialProfile(
    k_config.bsc_damp_profile_velocity_min,
    k_config.bsc_damp_profile_velocity_max,
    k_config.bsc_damp_profile_weight_min,
    k_config.bsc_damp_profile_weight_max,
    k_config.bsc_damp_profile_exp);
  m_profile_amplify = new BinomialProfile(
    k_config.bsc_amplify_profile_velocity_min,
    k_config.bsc_amplify_profile_velocity_max,
    k_config.bsc_amplify_profile_weight_min,
    k_config.bsc_amplify_profile_weight_max,
    k_config.bsc_amplify_profile_exp);
  m_weight = 1.0;
}

BrakeStepController::~BrakeStepController() {
  delete m_profile_damp;
  delete m_profile_amplify;
  delete[] m_error_history;
}

float BrakeStepController::update(float k_step_size,
                                  float k_altitude_error,
                                  float k_velocity)
{
  // Shift history down and log the new error
  for (unsigned int i = 0; i < mERROR_HISTORY_SIZE - 1; i++)
    m_error_history[i] = m_error_history[i + 1];

  m_error_history[mERROR_HISTORY_SIZE - 1] = k_altitude_error;
  m_iterations++;

  if (m_iterations >= mERROR_HISTORY_SIZE) {
    unsigned int sign_swaps = 0;

    // Evaluate extremity of oscillation
    for (unsigned int i = 1; i < mERROR_HISTORY_SIZE; i++)
      if (util::sign(m_error_history[i]) != util::sign(m_error_history[i - 1]))
        sign_swaps++;

    float swap_proportion = sign_swaps * 1.0 / (mERROR_HISTORY_SIZE - 1);

    if (swap_proportion >= mTHRESH_OSCILLATION) {
      // Oscillation threshold exceeded; step size must come down
      float damp = m_profile_damp->get(k_velocity);
      m_weight = util::clamp(0.0f, 1.0f, m_weight - damp);
    } else if (swap_proportion < mTHRESH_STABILITY) {
      // Stability threshold exceeded; step size must go up
      float amplify = m_profile_amplify->get(k_velocity);
      m_weight = util::clamp(0.0f, 1.0f, m_weight + amplify);
    }
  }

  return k_step_size * m_weight;
}

float BrakeStepController::get_weight() const {
  return m_weight;
}

void BrakeStepController::set_weight(float k_weight) {
  m_weight = k_weight;
}

}; // end namespace aimbot
