#ifndef AIMBOT_CD_PLANE_HPP
#define AIMBOT_CD_PLANE_HPP

namespace aimbot {

typedef struct {
  float* plane;
  float alt_low;
  float alt_high;
  float alt_step;
  float vel_low;
  float vel_high;
  float vel_step;
} cd_plane_t;

float cd_at(const cd_plane_t& k_plane, float k_s, float k_v);

} // namespace aimbot

#endif
