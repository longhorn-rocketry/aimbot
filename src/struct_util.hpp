#ifndef AIMBOT_STRUCT_UTIL_HPP
#define AIMBOT_STRUCT_UTIL_HPP

namespace aimbot {

static unsigned int float_struct_binsearch(const void* k_arr,
                                           float k_ref,
                                           unsigned int k_struct_size,
                                           unsigned int k_ref_offset,
                                           unsigned int k_bound_low,
                                           unsigned int k_bound_high);

unsigned int float_struct_binsearch(const void* k_arr,
                                    float k_ref,
                                    unsigned int k_arr_size,
                                    unsigned int k_struct_size,
                                    unsigned int k_ref_offset);

}; // end namespace aimbot

#endif
