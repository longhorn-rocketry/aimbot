#ifndef AIMBOT_AIRBRAKE_MODEL_HPP
#define AIMBOT_AIRBRAKE_MODEL_HPP

#include "cd_model.hpp"
#include "drag_force.hpp"

namespace aimbot {

const float gCD_FLAT_PLANE = 1.28;

class AirbrakeModel {
protected:
  CdModel* m_cd_model;

public:
  AirbrakeModel(CdModel* k_cd_model);

  virtual float net_drag(const rocket_t& k_rocket,
                         const state_t& k_state,
                         float k_extension) = 0;
};

} // end namespace aimbot

#endif
