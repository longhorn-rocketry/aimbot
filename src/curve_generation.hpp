#ifndef AIMBOT_CURVE_GENERATION_HPP
#define AIMBOT_CURVE_GENERATION_HPP

#include "cd_schedule.hpp"
#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

  namespace cgen {

    typedef struct AltitudeBounds {
      float lower;
      float upper;
    } bounds_t;

    static float timestep = 0.01;

    static CdSchedule* rocket_cd_sched;
    static CdSchedule* airbrake_cd_sched;

    void set_timestep(float k_timestep);

    void set_rocket_cd_schedule(CdSchedule* k_sched);

    void set_airbrake_cd_schedule(CdSchedule* k_sched);

    bounds_t integrate_euler(const rocket_t& k_rocket, const state_t& k_state);

  }; // end namespace cgen

}; // end namespace cgen

#endif
