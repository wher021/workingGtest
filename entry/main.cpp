#include "../entry/ipv4/ipv4module.h"
#include "gmock/gmock.h"



int main(int argc, char* argv[]) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
