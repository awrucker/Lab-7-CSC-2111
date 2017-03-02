#if !defined (MULTIVARFUNCTION_H)
#define MULTIVARFUNCTION_H

class MultiVarFunction
{
   private:

   public:
      MultiVarFunction() {};
      ~MultiVarFunction() {};
      virtual double evaluate(double* xy) = 0;
};

#endif
