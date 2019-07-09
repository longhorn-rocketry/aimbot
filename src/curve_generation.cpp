#include "curve_generation.hpp"

namespace aimbot {

  namespace cgen {

    void set_timestep(float k_timestep) {
      timestep = k_timestep;
    }

    void set_rocket_cd_schedule(CdSchedule* k_sched) {
      rocket_cd_sched = k_sched;
    }

    void set_airbrake_cd_schedule(CdSchedule* k_sched) {
      airbrake_cd_sched = k_sched;
    }

    bounds_t integrate_euler(const rocket_t& k_rocket,
                             const state_t& k_state)
    {
      bounds_t bounds;
      rocket_t rocket_extrap = k_rocket;
      state_t state_extrap = k_state;

      // Upper bound, airbrakes retracted
      while (state_extrap.velocity > 0) {
        float cd = rocket_cd_sched->get_cd(state_extrap.velocity);
        rocket_extrap.drag_coefficient = cd;
        float a = simple_net_acceleration(rocket_extrap, state_extrap);
        state_extrap.velocity += a * timestep;
        state_extrap.altitude += state_extrap.velocity * timestep;
      }

      bounds.upper = state_extrap.altitude;
      rocket_extrap = k_rocket;
      state_extrap = k_state;

      // Lower bound, airbrakes extended
      while (state_extrap.velocity > 0) {
        float cd = rocket_cd_sched->get_cd(state_extrap.velocity);
        rocket_extrap.drag_coefficient =
            cd + airbrake_cd_sched->get_cd(state_extrap.velocity);
        float a = simple_net_acceleration(rocket_extrap, state_extrap);
        state_extrap.velocity += a * timestep;
        state_extrap.altitude += state_extrap.velocity * timestep;
      }

      bounds.lower = state_extrap.altitude;

      return bounds;
    }

  }; // end namespace cgen

}; // end namespace aimbot
