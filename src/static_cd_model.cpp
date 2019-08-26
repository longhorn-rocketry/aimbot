#include "static_cd_model.hpp"

namespace aimbot {

StaticCdModel::StaticCdModel(float k_static_cd) : mSTATIC_CD(k_static_cd) {}

float StaticCdModel::get_cd(const rocket_t& k_rocket, const state_t& k_state) {
  return mSTATIC_CD;
}

} // end namespace aimbot
