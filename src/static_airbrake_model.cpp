#include "standard_atmosphere.hpp"
#include "static_airbrake_model.hpp"

namespace aimbot {

StaticAirbrakeModel::StaticAirbrakeModel(CdModel* k_cd_model) :
  AirbrakeModel(k_cd_model) {}

float StaticAirbrakeModel::net_drag(const rocket_t& k_rocket,
                                    const state_t& k_state,
                                    float k_extension)
{
  float air_density = atmos::air_density_at(k_state.altitude);
  float rocket_cd = m_cd_model->get_cd(k_rocket, k_state);
  float rocket_drag = simple_drag_force(
    air_density, k_state.velocity, rocket_cd, k_rocket.surface_area
  );
  float airbrake_drag = simple_drag_force(
    air_density, k_state.velocity, gCD_FLAT_PLANE,
    k_rocket.airbrake_surface_area * k_extension
  );
  return rocket_drag + airbrake_drag;
}

} // end namespace aimbot
