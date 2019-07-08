#include "standard_atmosphere.hpp"

namespace aimbot {

float atmos::interpolate_linear(float kA, float kB, float kP) {
  return kA + (kB - kA) * kP;
}

int atmos::closest_conditions_index(float kAltitude) {
  if (kAltitude < atmos::STANDARD_ATMOSPHERE[0].altitude)
    return atmos::ATMOS_ERROR;

  for (int i = 1; i < atmos::STANDARD_ATMOSPHERE_SIZE; i++)
    if (atmos::STANDARD_ATMOSPHERE[i].altitude >= kAltitude)
      return i - 1;

  return atmos::ATMOS_ERROR;
}

float atmos::read_atmos_t_value(const atmos_t* kAtmos, unsigned int kOffset) {
  const char* alias = (char*)kAtmos;
  return *((float*)(alias + kOffset));
}

float atmos::interpolate_atmos_t_value(float kAltitude, unsigned int kOffset) {
  int index = atmos::closest_conditions_index(kAltitude);

  if (index != atmos::ATMOS_ERROR) {
    const atmos::atmos_t& conditions_low = atmos::STANDARD_ATMOSPHERE[index];
    const atmos::atmos_t& conditions_high = atmos::STANDARD_ATMOSPHERE[index+1];
    float val_low = atmos::read_atmos_t_value(&conditions_low, kOffset);
    float val_high = atmos::read_atmos_t_value(&conditions_high, kOffset);
    float p = (kAltitude - conditions_low.altitude)
              / (conditions_high.altitude - conditions_low.altitude);
    return atmos::interpolate_linear(val_low, val_high, p);
  }

  return atmos::ATMOS_ERROR;
}

float atmos::temperature_at(float kAltitude) {
  return atmos::interpolate_atmos_t_value(kAltitude, TEMPERATURE_BYTE_OFFSET);
}

float atmos::gravity_at(float kAltitude) {
  return atmos::interpolate_atmos_t_value(kAltitude, GRAVITY_BYTE_OFFSET);
}

float atmos::pressure_at(float kAltitude) {
  return atmos::interpolate_atmos_t_value(kAltitude, PRESSURE_BYTE_OFFSET);
}

float atmos::air_density_at(float kAltitude) {
  return atmos::interpolate_atmos_t_value(kAltitude, AIR_DENSITY_BYTE_OFFSET);
}

float atmos::dynamic_viscosity_at(float kAltitude) {
  return atmos::interpolate_atmos_t_value(kAltitude,
                                          DYNAMIC_VISCOSITY_BYTE_OFFSET);
}

}; // end namespace aimbot
