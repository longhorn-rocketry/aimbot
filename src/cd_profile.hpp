#ifndef AIMBOT_CD_SCHEDULE_HPP
#define AIMBOT_CD_SCHEDULE_HPP

namespace aimbot {

typedef struct {
  float param;
  float cd;
} cd_event_t;

typedef struct {
  cd_event_t* events;
  unsigned int size;
} cd_profile_t;

float cd_at(const cd_profile_t& k_profile, float k_param);

}; // end namespace aimbot

#endif
