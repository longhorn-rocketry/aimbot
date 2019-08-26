#include "schedule_cd_model.hpp"

namespace aimbot {

ScheduleCdModel::ScheduleCdModel(const cd_profile_t& k_cd_profile) :
  mCD_PROFILE(k_cd_profile) {}

float ScheduleCdModel::get_cd(const rocket_t& k_rocket,
                              const state_t& k_state)
{
  return cd_at(mCD_PROFILE, k_state.altitude);
}

} // end namespace aimbot
