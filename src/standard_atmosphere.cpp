#include "standard_atmosphere.hpp"

namespace atmos {

float interpolate_linear(float kA, float kB, float kP) {
  return kA + (kB - kA) * kP;
}

int closest_conditions_index(float kAltitude) {
  if (kAltitude < STANDARD_ATMOSPHERE[0].altitude)
    return ATMOS_ERROR;

  for (int i = 1; i < STANDARD_ATMOSPHERE_SIZE; i++)
    if (STANDARD_ATMOSPHERE[i].altitude >= kAltitude)
      return i - 1;

  return ATMOS_ERROR;
}

float read_atmos_t_value(const atmos_t* kAtmos, unsigned int kOffset) {
  const char* alias = (char*)kAtmos;
  return *((float*)(alias + kOffset));
}

float interpolate_atmos_t_value(float kAltitude, unsigned int kOffset) {
  int index = closest_conditions_index(kAltitude);

  if (index != ATMOS_ERROR) {
    const atmos_t& conditions_low = STANDARD_ATMOSPHERE[index];
    const atmos_t& conditions_high = STANDARD_ATMOSPHERE[index+1];
    float val_low = read_atmos_t_value(&conditions_low, kOffset);
    float val_high = read_atmos_t_value(&conditions_high, kOffset);
    float p = (kAltitude - conditions_low.altitude)
              / (conditions_high.altitude - conditions_low.altitude);
    return interpolate_linear(val_low, val_high, p);
  }

  return ATMOS_ERROR;
}

float temperature_at(float kAltitude) {
  return interpolate_atmos_t_value(kAltitude, TEMPERATURE_BYTE_OFFSET);
}

float gravity_at(float kAltitude) {
  return interpolate_atmos_t_value(kAltitude, GRAVITY_BYTE_OFFSET);
}

float pressure_at(float kAltitude) {
  return interpolate_atmos_t_value(kAltitude, PRESSURE_BYTE_OFFSET);
}

float air_density_at(float kAltitude) {
  return interpolate_atmos_t_value(kAltitude, AIR_DENSITY_BYTE_OFFSET);
}

float dynamic_viscosity_at(float kAltitude) {
  return interpolate_atmos_t_value(kAltitude, DYNAMIC_VISCOSITY_BYTE_OFFSET);
}

}; // end namespace aimbot
