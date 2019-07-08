#ifndef TESTING_UTIL_HPP
#define TESTING_UTIL_HPP

#define NOT_APPROX(f, f_exp) {                                                 \
          std::string s = util::not_approx_msg(f, f_exp);                      \
          FAIL(s.c_str());                                                     \
        }

#include <string>

namespace util {

bool approx(float a, float b);

std::string not_approx_msg(float a, float b);

}; // end namespace util

#endif
