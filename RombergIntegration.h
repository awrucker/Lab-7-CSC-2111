/*
	Cong Tuan Nguyen && Adam Rucker
	3/3/2017
	Lab 7/ RombergIntegration Lab
*/	
#if !defined (ROMBERGINTEGRATION_H)
#define ROMBERGINTEGRATION_H

#include "MultiVarFunction.h"

class RombergIntegration
{

   private:

   public:
		/*
			Pre: Receives a MultiVarFunction* a double a second double and an integer
			Post: Returns a double with the specific level of RombergIntegration levels done.
		*/	
      static double accurateRomberg(MultiVarFunction* f, double a, double b, int level);
      
};

#endif
