#include "airflow_deflection_airbrake_model.hpp"
#include "drag_force.hpp"
#include "standard_atmosphere.hpp"

namespace aimbot {

AirflowDeflectionAirbrakeModel::AirflowDeflectionAirbrakeModel(
  CdModel* k_cd_model, float k_rho) : AirbrakeModel(k_cd_model), mRHO(k_rho) {}

float AirflowDeflectionAirbrakeModel::net_drag(const rocket_t& k_rocket,
                                               const state_t& k_state,
                                               float k_extension)
{
  float air_density = atmos::air_density_at(k_state.altitude);
  float rocket_cd = m_cd_model->get_cd(k_rocket, k_state);
  float rocket_damped_cd = rocket_cd - (1 - mRHO) * rocket_cd * k_extension;
  float rocket_drag = simple_drag_force(
    air_density, k_state.velocity, rocket_damped_cd, k_rocket.surface_area
  );
  float airbrake_drag = simple_drag_force(
    air_density, k_state.velocity, gCD_FLAT_PLANE,
    k_extension * k_rocket.airbrake_surface_area
  );
  return rocket_drag + airbrake_drag;
}

} // end namespace aimbot
