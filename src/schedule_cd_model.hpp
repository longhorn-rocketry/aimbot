#ifndef AIMBOT_SCHEDULE_CD_MODEL_HPP
#define AIMBOT_SCHEDULE_CD_MODEL_HPP

#include "cd_model.hpp"
#include "cd_profile.hpp"

namespace aimbot {

class ScheduleCdModel : public CdModel {
protected:
  const cd_profile_t mCD_PROFILE;

public:
  ScheduleCdModel(const cd_profile_t& k_cd_profile);

  float get_cd(const rocket_t& k_rocket, const state_t& k_state);
};

} // end namespace aimbot

#endif
