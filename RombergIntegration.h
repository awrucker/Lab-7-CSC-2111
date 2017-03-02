#if !defined (ROMBERGINTEGRATION_H)
#define ROMBERGINTEGRATION_H

#include "MultiVarFunction.h"

class RombergIntegration
{

   private:

   public:
      static double accurateRomberg(MultiVarFunction* f, double a, double b, int level);
      
};

#endif
