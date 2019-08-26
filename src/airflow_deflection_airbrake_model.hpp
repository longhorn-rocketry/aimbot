#ifndef AIMBOT_AIRFLOW_DEFLECTION_AIRBRAKE_MODEL_HPP
#define AIMBOT_AIRFLOW_DEFLECTION_AIRBRAKE_MODEL_HPP

#include "airbrake_model.hpp"
#include "cd_plane.hpp"

namespace aimbot {

/**
 * The airflow deflection airbrake model assumes that the deployment of the
 * airbrakes deflects significant amounts of airflow away from the body of the
 * rocket, thereby decreasing the wetted area contributing to friction drag.
 * The rate of decrease is directly proportional to airbrake extension. Herein,
 * "rho" is the weight of the base rocket cd at full extension, i.e. rho=0.75
 * signifies that at 100% airbrake extension, the base rocket cd has been
 * lowered by 25%. The airbrake drag is added on top of the base drag.
 */
class AirflowDeflectionAirbrakeModel : public AirbrakeModel {
protected:
  const float mRHO;

public:
  AirflowDeflectionAirbrakeModel(CdModel* k_cd_model, float k_rho);

  float net_drag(const rocket_t& k_rocket,
                 const state_t& k_state,
                 float k_extension);
};

} // end namespace aimbot

#endif
