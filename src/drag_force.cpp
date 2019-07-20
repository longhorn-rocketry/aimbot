#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

float simple_drag_force(const rocket_t& k_rocket,
                        const state_t& k_state,
                        float k_cd)
{
  float air_density = atmos::air_density_at(k_state.altitude);
  return 0.5 * air_density * k_state.velocity * k_state.velocity
         * k_cd * k_rocket.surface_area;
}

float net_acceleration(const rocket_t& k_rocket,
                       const state_t& k_state,
                       float k_drag_force)
{
  float gravity = atmos::gravity_at(k_state.altitude);
  return -(k_drag_force / k_rocket.mass) - gravity;
}

float simple_net_acceleration(const rocket_t& k_rocket,
                              const state_t& k_state)
{
  float drag = simple_drag_force(k_rocket, k_state, k_rocket.drag_coefficient);
  return net_acceleration(k_rocket, k_state, drag);
}

float profiled_net_acceleration(const rocket_t& k_rocket,
                                const state_t& k_state,
                                const cd_profile_t& k_cd_profile)
{
  float cd = cd_at(k_cd_profile, k_state.velocity / gMACH1);
  float drag = simple_drag_force(k_rocket, k_state, cd);
  return net_acceleration(k_rocket, k_state, drag);
}

}; // end namespace aimbot
