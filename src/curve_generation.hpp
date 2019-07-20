#ifndef AIMBOT_CURVE_GENERATION_HPP
#define AIMBOT_CURVE_GENERATION_HPP

#include "cd_profile.hpp"
#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

  namespace cgen {

    typedef struct AltitudeBounds {
      float lower;
      float upper;
    } bounds_t;

    static float timestep = 0.01;

    static cd_profile_t* rocket_cd_profile;
    static cd_profile_t* airbrake_cd_profile;

    void set_timestep(float k_timestep);

    void set_rocket_cd_profile(cd_profile_t* k_sched);

    void set_airbrake_cd_profile(cd_profile_t* k_sched);

    bounds_t integrate_euler(const rocket_t& k_rocket, const state_t& k_state);

  }; // end namespace cgen

}; // end namespace cgen

#endif
