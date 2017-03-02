#if !defined (PROB221_H)
#define PROB221_H

#include "MultiVarFunction.h"

class Problem22_1 : public MultiVarFunction
{
   private:
      double lower;
      double upper;

   public:
      Problem22_1();
      ~Problem22_1();
      double evaluate(double* xy);
      double integrate(int level);
      void setLowerLimit(double a);
      void setUpperLimit(double b);

};

#endif
