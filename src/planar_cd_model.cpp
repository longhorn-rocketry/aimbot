#include "planar_cd_model.hpp"

namespace aimbot {

PlanarCdModel::PlanarCdModel(const cd_plane_t& k_cd_plane) :
  mCD_PLANE(k_cd_plane) {}

float PlanarCdModel::get_cd(const rocket_t& k_rocket, const state_t& k_state) {
  return cd_at(mCD_PLANE, k_state.altitude, k_state.velocity);
}

} // end namespace aimbot
