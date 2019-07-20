#include "cd_profile.hpp"
#include "standard_atmosphere.hpp"
#include "struct_util.hpp"

namespace aimbot {

float cd_at(const cd_profile_t& k_profile, float k_param) {
  if (k_param <= k_profile.events[0].param)
    return k_profile.events[0].cd;
  else if (k_param >= k_profile.events[k_profile.size - 1].param)
    return k_profile.events[k_profile.size - 1].cd;

  unsigned int pos = aimbot::float_struct_binsearch(k_profile.events,
                                                    k_param,
                                                    k_profile.size,
                                                    sizeof(cd_event_t),
                                                    0);
  const cd_event_t& event_low = k_profile.events[pos - 1];
  const cd_event_t& event_high = k_profile.events[pos];

  float cd_low = event_low.cd;
  float cd_high = event_high.cd;
  float p = (k_param - event_low.param) / (event_high.param - event_low.param);

  return atmos::interpolate_linear(cd_low, cd_high, p);
}

}; // end namespace aimbot
