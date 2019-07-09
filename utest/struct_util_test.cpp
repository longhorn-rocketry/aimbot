#include <CppUTest/TestHarness.h>

#include "struct_util.hpp"
#include "testing_util.hpp"

using namespace aimbot;

TEST_GROUP(StructUtilTest)
{
};

TEST(StructUtilTest, FloatBinsearch)
{
  typedef struct FloatPair {
    float a;
    float b;
  } pair_t;

  const pair_t ARR[] = {
    {1, 5},
    {5, 20},
    {17, 25},
    {67, 90}
  };

  int pos = float_struct_binsearch(&ARR, 3, 4, 8, 0);
  CHECK_EQUAL(1, pos);

  pos = float_struct_binsearch(&ARR, 18, 4, 8, 0);
  CHECK_EQUAL(3, pos);

  pos = float_struct_binsearch(&ARR, 5, 4, 8, 0);
  CHECK_EQUAL(1, pos);

  pos = float_struct_binsearch(&ARR, 3, 4, 8, 4);
  CHECK_EQUAL(0, pos);

  pos = float_struct_binsearch(&ARR, 100, 4, 8, 0);
  CHECK_EQUAL(4, pos);
}
