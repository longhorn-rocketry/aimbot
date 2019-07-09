#ifndef AIMBOT_CURVE_GENERATION_HPP
#define AIMBOT_CURVE_GENERATION_HPP

namespace cgen {

typedef struct AltitudeBounds {
  float lower;
  float upper;
} bounds_t;

static float extrapolation_timestep = 0.01;

void set_extrapolation_timestep(float k_timestep);

}; // end namespace cgen

#endif
