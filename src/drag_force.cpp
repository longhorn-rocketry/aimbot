#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

float simple_drag_force(const rocket_t& kRocket, const state_t& kState) {
  float air_density = atmos::air_density_at(kState.altitude);
  return 0.5 * air_density * kState.velocity * kState.velocity
         * kRocket.drag_coefficient * kRocket.surface_area;
}

float net_acceleration(const rocket_t& kRocket,
                       const state_t& kState,
                       float kDragForce)
{
  float gravity = atmos::gravity_at(kState.altitude);
  return -(kDragForce / kRocket.mass) - gravity;
}

float simple_net_acceleration(const rocket_t& kRocket, const state_t& kState) {
  float drag = simple_drag_force(kRocket, kState);
  return net_acceleration(kRocket, kState, drag);
}

}; // end namespace aimbot
