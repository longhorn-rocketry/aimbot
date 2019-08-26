#ifndef AIMBOT_STATIC_AIRBRAKE_MODEL_HPP
#define AIMBOT_STATIC_AIRBRAKE_MODEL_HPP

#include "airbrake_model.hpp"
#include "cd_plane.hpp"

namespace aimbot {

class StaticAirbrakeModel : public AirbrakeModel {
public:
  StaticAirbrakeModel(CdModel* k_cd_model);

  float net_drag(const rocket_t& k_rocket,
                 const state_t& k_state,
                 float k_extension);
};

} // end namespace aimbot

#endif
