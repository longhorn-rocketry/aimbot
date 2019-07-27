#include "cd_plane.hpp"

namespace aimbot {

float cd_at(const cd_plane_t& k_plane, float k_s, float k_v) {
  if (k_s < k_plane.alt_low)
    k_s = k_plane.alt_low;
  else if (k_s > k_plane.alt_high)
    k_s = k_plane.alt_high;

  if (k_v < k_plane.vel_low)
    k_v = k_plane.vel_low;
  else if (k_v > k_plane.vel_high)
    k_v = k_plane.vel_high;

  float alt_range = k_plane.alt_high - k_plane.alt_low;
  float vel_range = k_plane.vel_high - k_plane.vel_low;

  unsigned long alt_steps = alt_range / k_plane.alt_step;
  unsigned long vel_steps = vel_range / k_plane.vel_step;
  unsigned long alt_index = (k_s - k_plane.alt_low) / alt_range
                            * alt_steps;
  unsigned long vel_index = (k_v - k_plane.vel_low) / vel_range
                            * vel_steps;

  unsigned long plane_index = alt_steps * vel_index + alt_index;
  return k_plane.plane[plane_index];
}

} // namespace aimbot
