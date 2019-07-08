/**
 * Defines utilities for calculating acceleration
 */

#ifndef _CURVE_GEN_ACCELERATION_CALCULATOR_H_
#define _CURVE_GEN_ACCELERATION_CALCULATOR_H_

#define GRAVITY 9.80665

// #include <array>
// #include <cassert>
// #include <utility>

#include "constant_area_drag_calculator.h"
#include "interpolate.h"

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
);

#endif // _CURVE_GEN_ACCELERATION_CALCULATOR_H_
