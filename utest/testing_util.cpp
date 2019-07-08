#include <math.h>

#include "testing_util.hpp"

namespace util {

bool approx(float a, float b) {
  return fabs(a - b) < 0.01;
}

std::string not_approx_msg(float a, float b) {
  return std::to_string(a) + " !~= " + std::to_string(b);
}

}; // end namespace util
