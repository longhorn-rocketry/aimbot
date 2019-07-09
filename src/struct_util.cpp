#include "struct_util.hpp"

namespace aimbot {

unsigned int float_struct_binsearch(const void* k_arr,
                                    float k_ref,
                                    unsigned int k_struct_size,
                                    unsigned int k_ref_offset,
                                    unsigned int k_bound_low,
                                    unsigned int k_bound_high)
{
  int midpoint = k_bound_low + (k_bound_high - k_bound_low) / 2;

  if (k_bound_high - k_bound_low < 1)
    return midpoint;

  const char* arr_alias = (char*)k_arr;
  float mid_ref = *((float*)(arr_alias + k_struct_size * midpoint
                             + k_ref_offset));

  if (mid_ref == k_ref)
    return midpoint;
  else if (mid_ref < k_ref)
    return float_struct_binsearch(k_arr, k_ref, k_struct_size, k_ref_offset,
                                  midpoint + 1,
                                  k_bound_high);
  else
    return float_struct_binsearch(k_arr, k_ref, k_struct_size, k_ref_offset,
                                  k_bound_low,
                                  midpoint);
}

unsigned int float_struct_binsearch(const void* k_arr,
                                    float k_ref,
                                    unsigned int k_arr_size,
                                    unsigned int k_struct_size,
                                    unsigned int k_ref_offset)
{
  return float_struct_binsearch(k_arr, k_ref, k_struct_size, k_ref_offset,
                                0,
                                k_arr_size);
}

}; // end namespace aimbot
