#ifndef AIMBOT_DRAG_FORCE_HPP
#define AIMBOT_DRAG_FORCE_HPP

namespace aimbot {

typedef struct RocketProperties {
  float mass;
  float radius;
  float surface_area;
  float drag_coefficient;
  float nosecone_length;
  float fineness;
  float skin_roughness;
} rocket_t;

typedef struct RocketState {
  float altitude;
  float velocity;
} state_t;

float simple_drag_force(const rocket_t& kRocket, const state_t& kState);

static float net_acceleration(const rocket_t& kRocket,
                              const state_t& kState,
                              float kDragForce);

float simple_net_acceleration(const rocket_t& kRocket, const state_t& kState);

}; // end namespace aimbot

#endif
