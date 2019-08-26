#ifndef AIMBOT_UTIL_HPP
#define AIMBOT_UTIL_HPP

namespace aimbot {

  namespace util {

    template<typename T>
    T clamp(T k_low, T k_high, T k_val) {
      return k_val < k_low ? k_low : (k_val > k_high ? k_high : k_val);
    }

    template<typename T>
    int sign(T k_val) {
      return k_val < 0 ? -1 : (k_val > 0 ? 1 : 0);
    }
  } // end namespace util

} // end namespace aimbot

#endif
