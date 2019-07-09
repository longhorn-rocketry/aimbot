#include "cd_schedule.hpp"
#include "standard_atmosphere.hpp"
#include "struct_util.hpp"

namespace aimbot {

CdSchedule::CdSchedule(const cdpoint_t* k_points,
                       const unsigned int k_points_size) :
  mPOINTS(k_points),
  mPOINTS_SIZE(k_points_size) {}

float CdSchedule::get_cd(float k_param) const {
  if (k_param >= mPOINTS[mPOINTS_SIZE - 1].param)
    return mPOINTS[mPOINTS_SIZE - 1].cd;
  else if (k_param <= mPOINTS[0].param)
    return mPOINTS[0].cd;

  unsigned int index = float_struct_binsearch(mPOINTS,
                                              k_param,
                                              mPOINTS_SIZE,
                                              sizeof(cdpoint_t),
                                              4);

  if (index == 0)
    return mPOINTS[index].cd;

  const cdpoint_t& point_low = mPOINTS[index - 1];
  const cdpoint_t& point_high = mPOINTS[index];

  float p = (k_param - point_low.param) / (point_high.param - point_low.param);

  return atmos::interpolate_linear(point_low.cd, point_high.cd, p);
}

}; // end namespace aimbot
