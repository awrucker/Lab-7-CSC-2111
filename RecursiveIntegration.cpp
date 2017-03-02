#include "RecursiveIntegration.h"
#include <math.h>

//this method is here for 1-d integration (a convenience method)
//the integration limits are placed in arrays of size 1, and other methods are called
double RecursiveIntegration::romberg(MultiVarFunction* f, double a, double b, int n)
{
   double* aa = new double[1];
   aa[0] = a;
   double* bb = new double[1];
   bb[0] = b;
   double result = romberg(f, aa, bb, n, 1);
   delete[] aa;
   delete[] bb;
   return result;
}

//this is the difficult method that uses recursion based on the dimension of the integral
//usually, n2 = 2*n1, but this is not required
double RecursiveIntegration::romberg(MultiVarFunction* f, double* a, double* b, int n, int numVars)
{
   int dim = numVars;

   double* coords = new double[dim];
   double result = rombergRec(f, dim - 1, a, b, n, coords);

   delete[] coords;
   return result;
}

//the private recursive method
double RecursiveIntegration::rombergRec(MultiVarFunction* f, int dim, double* a, double* b, int n, double* coords)
{
   //each level of recursion needs storage space
   double* evals = new double[n + 1];
   double h = (b[dim] - a[dim])/n;

   coords[dim] = a[dim];  //need to reset for each pass

   for (int j = 0; j <= n; j++)  //loop over the number of points (number of intervals plus one)
   {
      if (dim == 0)  //base case, function evaluation
      {
         evals[j] = f->evaluate(coords);
      }
      else
      {
         evals[j] = rombergRec(f, dim - 1, a, b, n, coords);
      }

      coords[dim] = coords[dim] + h;
   }
      
   double result = trap(evals, n, a[dim], b[dim]);
   delete[] evals;

   return result;
}

//perform a multiple interval trapezoid rule computation 
//using an array of function evaluations
double RecursiveIntegration::trap(double* f, int n, double a, double b)
{
   double result = f[0];  //the first function evaluation is added in one time

   for (int i = 1; i <= n - 1; i++)
   {
      result += 2*f[i];  //the interior function evaluations are added in twice
   }

   result += f[n];  //the last function evaluation is added in one time
   result = (b - a) * result / (2 * n);  //h is (b - a)/n

   return result;
}
