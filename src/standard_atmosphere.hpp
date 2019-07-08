#ifndef AIMBOT_STANDARD_ATMOSPHERE_HPP
#define AIMBOT_STANDARD_ATMOSPHERE_HPP

namespace aimbot {

  namespace atmos {
    /**
     * Air properties at an altitude.
     */
    typedef struct AtmosphericConditions {
      float altitude;          // m
      float temperature;       // C
      float gravity;           // m/s^2s
      float pressure;          // N/m^2m
      float air_density;       // kg/m^3
      float dynamic_viscosity; // N*s/m^2
    } atmos_t;

    static const unsigned int ALTITUDE_BYTE_OFFSET = 0;
    static const unsigned int TEMPERATURE_BYTE_OFFSET = 4;
    static const unsigned int GRAVITY_BYTE_OFFSET = 8;
    static const unsigned int PRESSURE_BYTE_OFFSET = 12;
    static const unsigned int AIR_DENSITY_BYTE_OFFSET = 16;
    static const unsigned int DYNAMIC_VISCOSITY_BYTE_OFFSET = 20;

    /**
     * US standard atmosphere air properties in SI units.
     * https://www.engineeringtoolbox.com/standard-atmosphere-d_604.html
     */
    static const atmos_t STANDARD_ATMOSPHERE[] = {
      {0,      15.0,    9.807,  10.13,  1.225,  1.789},
      {1000,    8.5,    9.804,   8.988, 1.112,  1.758},
      {2000,    2.0,    9.801,   7.95,  1.007,  1.726},
      {3000,   -4.49,   9.797,   7.012, 0.9093, 1.694},
      {4000,   -10.98,  9.794,   6.166, 0.8194, 1.661},
      {5000,   -17.47,  9.791,   5.405, 0.7364, 1.628},
      {6000,   -23.96,  9.788,   4.722, 0.6601, 1.595},
      {7000,   -30.45,  9.785,   4.111, 0.59,   1.561},
      {8000,   -36.94,  9.782,   3.565, 0.5258, 1.527},
      {9000,   -43.42,  9.779,   3.080, 0.4671, 1.493},
      {10000,  -49.9,   9.776,   2.650, 0.4135, 1.458}
    };
    static const unsigned int STANDARD_ATMOSPHERE_SIZE = 11;

    const int ATMOS_ERROR = -1;
    const atmos_t NOATMOS = {0, 0, 0, 0, 0, 0};

    static float read_atmos_t_value(const atmos_t* kAtmos,
                                    unsigned int kOffset);

    static float interpolate_atmos_t_value(float kAltitude,
                                           unsigned int kOffset);

    static float interpolate_linear(float kA, float kB, float kP);

    static int closest_conditions_index(float kAltitude);

    float temperature_at(float kAltitude);

    float gravity_at(float kAltitude);

    float pressure_at(float kAltitude);

    float air_density_at(float kAltitude);

    float dynamic_viscosity_at(float kAltitude);

  }; // end namespace atmos

}; // end namespace aimbot

#endif
