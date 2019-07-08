#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

float simple_drag_force(const rocket_t& kRocket, const state_t& kState) {
  float air_density = atmos::air_density_at(kState.altitude);
  return 0.5 * air_density * kState.velocity * kState.velocity
         * kRocket.drag_coefficient * kRocket.surface_area;
}

}; // end namespace aimbot
