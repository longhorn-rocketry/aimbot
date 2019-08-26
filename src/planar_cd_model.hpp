#ifndef AIMBOT_PLANAR_CD_MODEL_HPP
#define AIMBOT_PLANAR_CD_MODEL_HPP

#include "cd_model.hpp"
#include "cd_plane.hpp"

namespace aimbot {

class PlanarCdModel : public CdModel {
protected:
  const cd_plane_t mCD_PLANE;

public:
  PlanarCdModel(const cd_plane_t& k_cd_plane);

  float get_cd(const rocket_t& k_rocket, const state_t& k_state);
};

} // end namespace aimbot

#endif
