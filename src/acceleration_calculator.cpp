#include "acceleration_calculator.h"

double calculate_acceleration(
  /*std::pair<double, double> *collected_data,
  size_t collected_data_size,
  double base_mass,
  double velocity,
  double height,
  double start_height,
  double surface_area,
  double drag_coefficient,
  double time*/

  double mass,
  double velocity,
  double altitude,
  double altitude_initial,
  double rocket_surface_area,
  double airbrake_surface_area,
  double rocket_cd,
  double airbrake_cd
) {
  /*assert(collected_data_size >= 0);

  if (collected_data_size > 0 && collected_data != NULL) {
    std::pair<double, double> last_recorded_thrust = collected_data[collected_data_size - 1];

    if (time <= last_recorded_thrust.first) {
      return Interp(
        collected_data,
        collected_data_size,
        time
      );
    }
  }

  double drag = calculate_drag(
    start_height,
    height,
    surface_area,
    drag_coefficient,
    velocity
  );


  double weight = base_mass * GRAVITY;
  double force = -weight - drag;
  return force / base_mass;*/

  double rocket_drag = calculate_drag(
      altitude_initial,
      altitude,
      rocket_surface_area,
      rocket_cd,
      velocity);

  double airbrake_drag = calculate_drag(
      altitude_initial,
      altitude,
      airbrake_surface_area,
      airbrake_cd,
      velocity);

  double weight = mass * GRAVITY;
  double force = -weight - (rocket_drag + airbrake_drag);
  return force / mass;
}
