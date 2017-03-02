#if !defined (RECURSIVEINTEGRATION_H)
#define RECURSIVEINTEGRATION_H

#include "MultiVarFunction.h"

class RecursiveIntegration
{

   private:
      static double rombergRec(MultiVarFunction* f, int level, double* a, double* b, int n, double* coords);

   public:
      static double romberg(MultiVarFunction* f, double* a, double* b, int n, int numVars);
      static double romberg(MultiVarFunction* f, double a, double b, int n);  //1-d convenience method
      static double trap(double* f, int n, double a, double b);
      
};

#endif
