#include "standard_atmosphere.hpp"

namespace atmos {

float interpolate_linear(float k_a, float k_b, float k_p) {
  return k_a + (k_b - k_a) * k_p;
}

int closest_conditions_index(float k_altitude) {
  if (k_altitude < STANDARD_ATMOSPHERE[0].altitude)
    return ATMOS_ERROR;

  for (int i = 1; i < STANDARD_ATMOSPHERE_SIZE; i++)
    if (STANDARD_ATMOSPHERE[i].altitude >= k_altitude)
      return i - 1;

  return ATMOS_ERROR;
}

float read_atmos_t_value(const atmos_t* k_atmos, unsigned int k_offset) {
  const char* alias = (char*)k_atmos;
  return *((float*)(alias + k_offset));
}

float interpolate_atmos_t_value(float k_altitude, unsigned int k_offset) {
  int index = closest_conditions_index(k_altitude);

  if (index != ATMOS_ERROR) {
    const atmos_t& conditions_low = STANDARD_ATMOSPHERE[index];
    const atmos_t& conditions_high = STANDARD_ATMOSPHERE[index+1];
    float val_low = read_atmos_t_value(&conditions_low, k_offset);
    float val_high = read_atmos_t_value(&conditions_high, k_offset);
    float p = (k_altitude - conditions_low.altitude)
              / (conditions_high.altitude - conditions_low.altitude);
    return interpolate_linear(val_low, val_high, p);
  }

  return ATMOS_ERROR;
}

float temperature_at(float k_altitude) {
  return interpolate_atmos_t_value(k_altitude, TEMPERATURE_BYTE_OFFSET);
}

float gravity_at(float k_altitude) {
  return interpolate_atmos_t_value(k_altitude, GRAVITY_BYTE_OFFSET);
}

float pressure_at(float k_altitude) {
  return interpolate_atmos_t_value(k_altitude, PRESSURE_BYTE_OFFSET);
}

float air_density_at(float k_altitude) {
  return interpolate_atmos_t_value(k_altitude, AIR_DENSITY_BYTE_OFFSET);
}

float dynamic_viscosity_at(float k_altitude) {
  return interpolate_atmos_t_value(k_altitude, DYNAMIC_VISCOSITY_BYTE_OFFSET);
}

}; // end namespace aimbot
