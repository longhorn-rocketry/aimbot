#ifndef AIMBOT_DRAG_FORCE_HPP
#define AIMBOT_DRAG_FORCE_HPP

#include "cd_plane.hpp"
#include "cd_profile.hpp"

namespace aimbot {

const float gMACH1 = 343;

typedef struct RocketProperties {
  float mass;
  float radius;
  float surface_area;
  float airbrake_surface_area;
  float drag_coefficient;
  float nose_cone_length;
  float fineness;
  float skin_roughness;
} rocket_t;

typedef struct RocketState {
  float altitude;
  float velocity;
} state_t;

float simple_drag_force(float k_rho, float k_vel, float k_cd, float k_sa);

float simple_drag_force(const rocket_t& k_rocket,
                        const state_t& k_state,
                        float k_cd);

static float net_acceleration(const rocket_t& k_rocket,
                              const state_t& k_state,
                              float k_drag_force);

float simple_net_acceleration(const rocket_t& k_rocket,
                              const state_t& k_state);

float profiled_net_acceleration(const rocket_t& k_rocket,
                                const state_t& k_state,
                                const cd_profile_t& k_cd_profile);

float planar_net_acceleration(const rocket_t& k_rocket,
                              const state_t& k_state,
                              const cd_plane_t& k_cd_plane);

}; // end namespace aimbot

#endif
