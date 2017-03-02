#if !defined RANDOM_H
#define RANDOM_H

#include "randomc.h"

namespace CSC2110
{
class Random
{
   private:
      CRandomMother rand_mother;

   public:
      Random();
      int getRandomInt(int lower, int upper);
      float getRandomFloat(float lower, float upper); 
};
}

#endif
