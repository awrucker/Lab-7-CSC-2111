/*
	Cong Tuan Nguyen && Adam Rucker
*/	
#include "RombergIntegration.h"
#include "RecursiveIntegration.h"
#include "QueueLinked.h"
#include "Double.h"
using CSC2110::Double;

#include <math.h>

//a is the lower limit and b is the upper limit
double RombergIntegration::accurateRomberg(MultiVarFunction* f, double a, double b, int level)
{
   Double* db;  //use this variable to place and retrieve values on the queue
   
   QueueLinked<Double>* q1 = new QueueLinked<Double>();
   QueueLinked<Double>* q2 = new QueueLinked<Double>();


   int counter = 0;
   int n = 1;  //current number of intervals
   while (counter<= level)
   {
      //DO THIS
      //obtain the required number of trapezoid evaluations depending on the number of levels requested
      //put all of the level 0 results on the q1
	  double value = RecursiveIntegration::romberg(f, a, b, n);
	  db = new Double(value);
	  q1->enqueue(db);
      n = 2*n;  //double the number of intervals
      counter++;
   }

   //q1 now has all of the level 0 integration results

   double factor;  //use this to compute the current Romberg Factor (4^k stuff)
   int power = 1;  //k, used to compute the Romberg Factor

   //if level 0 has been requested, the loop will not execute
   //the total number of executions of the loop is ??

   //DO THIS
   int iterations = 0;               //can be precomputed
   for(int i =1; i <= level;i++)
   {
	   iterations += i;
   }
   while (iterations > 0)
   {
      //DO THIS
      //use the algorithm described in the lab to improve the accuracy of your level 0 results
	  factor = pow(4, power);
	  if(!(q1->isEmpty()))
	  {
		  Double* one = q1->dequeue();
		  Double* secondDb = q1->peek();
		  if(secondDb == NULL)
		  {
			  delete one;
			  while(!(q2->isEmpty()))
			  {
				db = q2->dequeue();
				q1->enqueue(db);
			  }
			  power++;
			  continue;
		  }
		  double x = ((factor* secondDb->getValue())-one->getValue())/(factor-1);
		  db = new Double(x);
		  q2->enqueue(db);
		  delete one;
	  }
	  
	 
	  


      iterations--;
   }

   //obtain the final answer
   db = q1->dequeue();
   double result = db->getValue();  
   delete db;

   delete q1;
   delete q2;

   return result;
}

