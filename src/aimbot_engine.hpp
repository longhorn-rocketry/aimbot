#ifndef AIMBOT_ENGINE_HPP
#define AIMBOT_ENGINE_HPP

#include "ab_control.hpp"
#include "airbrake_model.hpp"
#include "cd_model.hpp"

namespace aimbot {

class Engine {
public:
  enum ExtrapolationMethod {
    EXTRAP_EULER,
    EXTRAP_RK4,
    EXTRAP_RIEMANN
  };

  typedef struct {
    float min;
    float max;
    float extension;
  } step_t;

  Engine(CdModel* k_cd_model,
         AirbrakeModel* k_airbrake_model,
         ExtrapolationMethod k_extrap,
         float k_timestep,
         abc_config_t& k_abc_config);

  step_t update(float k_t, const rocket_t& k_rocket, const state_t& k_state);

protected:
  AirbrakeController* m_abc;
  CdModel* m_cd_model;
  AirbrakeModel* m_airbrake_model;
  ExtrapolationMethod m_extrap_method;
  float m_timestep;

  float extrapolate(const rocket_t& k_rocket,
                    const state_t& k_state,
                    float extension);

  float extrapolate_euler(const rocket_t& k_rocket,
                          const state_t& k_state,
                          float extension);
};

} // end namespace aimbot

#endif
