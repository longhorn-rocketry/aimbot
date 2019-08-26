#ifndef AIMBOT_CD_MODEL_HPP
#define AIMBOT_CD_MODEL_HPP

#include "drag_force.hpp"

namespace aimbot {

class CdModel {
public:
  virtual float get_cd(const rocket_t& k_rocket, const state_t& k_state) = 0;
};

} // end namespace aimbot

#endif
