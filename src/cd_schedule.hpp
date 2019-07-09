#ifndef AIMBOT_CD_SCHEDULE_HPP
#define AIMBOT_CD_SCHEDULE_HPP

namespace aimbot {

typedef struct CdPoint {
  float cd;
  float param;
} cdpoint_t;

class CdSchedule final {
private:
  const cdpoint_t* mPOINTS;
  const unsigned int mPOINTS_SIZE;

public:
  CdSchedule(const cdpoint_t* k_points, const unsigned int k_points_size);

  float get_cd(float k_param) const;
};

}; // end namespace aimbot

#endif
