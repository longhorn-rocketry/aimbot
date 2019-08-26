#ifndef AIMBOT_STATIC_CD_MODEL_HPP
#define AIMBOT_STATIC_CD_MODEL_HPP

#include "cd_model.hpp"

namespace aimbot {

class StaticCdModel : public CdModel {
protected:
  const float mSTATIC_CD;

public:
  StaticCdModel(float k_static_cd);

  float get_cd(const rocket_t& k_rocket, const state_t& k_state);
};

} // end namespace aimbot

#endif
