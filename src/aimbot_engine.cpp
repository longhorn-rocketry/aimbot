#include "aimbot_engine.hpp"
#include "standard_atmosphere.hpp"

#include <iostream>

namespace aimbot {

Engine::Engine(CdModel* k_cd_model,
               AirbrakeModel* k_airbrake_model,
               ExtrapolationMethod k_extrap,
               float k_timestep,
               abc_config_t& k_abc_config)
{
  m_abc = new AirbrakeController(k_abc_config);
  m_cd_model = k_cd_model;
  m_airbrake_model = k_airbrake_model;
  m_extrap_method = k_extrap;
  m_timestep = k_timestep;
}

Engine::step_t Engine::update(float k_t,
                              const rocket_t& k_rocket,
                              const state_t& k_state)
{
  Engine::step_t step;
  step.min = extrapolate(k_rocket, k_state, 1.0);
  step.max = extrapolate(k_rocket, k_state, 0.0);
  step.extension = m_abc->update(k_t, k_state.velocity, step.min, step.max);

  return step;
}

float Engine::extrapolate(const rocket_t& k_rocket,
                          const state_t& k_state,
                          float extension)
{
  if (m_extrap_method == EXTRAP_EULER)
    return extrapolate_euler(k_rocket, k_state, extension);
  else
    return 0 / 0;
}

float Engine::extrapolate_euler(const rocket_t& k_rocket,
                                const state_t& k_state,
                                float extension)
{
  state_t state_extrap = k_state;

  do {
    float a = atmos::gravity_at(state_extrap.altitude);
    float drag = m_airbrake_model->net_drag(k_rocket, state_extrap, extension);
    float net_a = a + drag / k_rocket.mass;
    state_extrap.velocity += -net_a * m_timestep;

    if (state_extrap.velocity > 0)
      state_extrap.altitude += state_extrap.velocity * m_timestep;
  } while (state_extrap.velocity > 0);

  return state_extrap.altitude;
}

} // end namespace aimbot
