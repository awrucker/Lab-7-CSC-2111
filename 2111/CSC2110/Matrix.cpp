#include "Matrix.h"
using CSC2110::Matrix;

#include <fstream>
#include <iostream>
using namespace std;
#include <cmath>

Matrix* Matrix::identity(int rows)
{
	Matrix* mat = new Matrix(rows, rows);
	for (int i = 1; i <= rows; i++)
	{
		for(int j = 1; j <= rows; j++)
		{
			mat->setElement(i, j, 0.0);
			if (i == j)
			{
				mat->setElement(i, j, 1.0);
			}
		}
	}
	
	return mat;
}

int Matrix::getNumRows()
{
   return rows;
}

int Matrix::getNumCols()
{
   return cols;
}

//the indices are 1-based!!
Matrix::Matrix(int r, int c)
{
   rows = r;
   cols = c;

   if (r < 1)
   {
      rows = 1;
   }

   if (c < 1)
   {
      cols = 1;
   }

   int num_elements = rows*cols;
   mat = new double[rows*cols];

   //initialize the matrix to contain all zeroes (might not be square in general)
   int count = 0;
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         mat[count] = 0.0;
         count++;
      }
   }
}

Matrix::~Matrix()
{
   delete[] mat;
}

void Matrix::setElement(int row, int col, double val)
{
   int index = (row - 1) * cols + col - 1;
   mat[index] = val;
}

double Matrix::getElement(int row, int col)
{
   int index = (row - 1) * cols + col - 1;
   return mat[index];
}

void Matrix::displayMatrix()
{
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         cout << this->getElement(i, j) << "   ";
      }
      cout << endl;
   }
   cout << endl;
}

Matrix* Matrix::add(Matrix* other)
{
   int rows1 = rows;
   int cols1 = cols;

   int rows2 = other->rows;  //getNumRows()
   int cols2 = other->cols;  //getNumCols()

   if (cols1 != rows1 || cols2 != rows2)
   {
      cout << "Cannot add matrices." << endl;
      return NULL;
   }

   Matrix* result = new Matrix(rows1, cols1);

   int rows = rows1;
   int cols = cols1;

   //loop over all elements of resulting matrix
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         double x = this->getElement(i, j) + other->getElement(i, j);
         result->setElement(i, j, x);
      }
   }

   return result;
}

Matrix* Matrix::multiply(Matrix* other)
{
   int rows1 = rows;
   int cols1 = cols;

   int rows2 = other->rows;
   int cols2 = other->cols;

   if (cols1 != rows2)
   {
      cout << "Cannot multiply matrices." << endl;
      return NULL;
   }

   Matrix* result = new Matrix(rows1, cols2);

   int rows = rows1;
   int cols = cols2;

   double x;

   //loop over all elements of resulting matrix
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         x = 0;
         //sum up multiplying matrices to obtain value placed in new matrix
         for (int k = 1; k <= cols1; k++)
         {
            x = x + this->getElement(i, k) * other->getElement(k, j);
         }
         result->setElement(i, j, x);
      }
   }

   return result;
}

//assumes a specific format for the file
Matrix* Matrix::readMatrix(const char* file_name)
{
   ifstream matrix_file;
   matrix_file.open(file_name);

   int rows = 1;
   int cols = 1;

   matrix_file >> rows >> cols;

   if (rows < 1)
   {
      rows = 1;
   }

   if (cols < 1)
   {
      cols = 1;
   }

   Matrix* matrix = new Matrix(rows, cols);

   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         double val = 0.0;
         matrix_file >> val;
         matrix->setElement(i, j, val);
      }
   }

   matrix_file.close();

   return matrix;
}

//assumes a specific format for the file
void Matrix::writeMatrix(const char* file_name)
{
   ofstream matrix_file;
   matrix_file.open(file_name);

   matrix_file << rows << " " << cols << endl;

   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         matrix_file << this->getElement(i, j) << " ";
      }
      matrix_file << endl;
   }

   matrix_file.close();
}

Matrix* Matrix::transpose()
{
   int rows = getNumRows();
   int cols = getNumCols();

   Matrix* result = new Matrix(cols, rows);

   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         result->setElement(j, i, getElement(i,j));
      }
   }
    
   return result;
}

//assumes a square matrix
Matrix** Matrix::PLU()
{
   int rows = getNumRows();
   int cols = getNumCols();

   Matrix* U = copy();
   Matrix* L = new Matrix(rows, cols);  
   for (int i = 1; i <= rows; i++)
   {
      L->setElement(i, i, 0); //don't want identity for L right now
   }
   Matrix* P = Matrix::identity(rows);

   for (int i = 1; i < rows; i++)
   {
      //find largest coefficient below the pivot element to avoid divide by zero
      double trial = fabs(getElement(i, i));
      int pivotRow1 = i;
      int pivotRow2 = pivotRow1;
      for (int j = i + 1; j <= rows; j++)
      {
         double temp = fabs(getElement(j, i));
         if (temp > trial) 
         {
            pivotRow2 = j;
            trial = temp;
         }
      }

      if (pivotRow1 < pivotRow2)
      {
         U->pivotRows(pivotRow1, pivotRow2);
         L->pivotRows(pivotRow1, pivotRow2);
         P->pivotRows(pivotRow1, pivotRow2);
      }
      L->setElement(i, i, 1.0);

      //multiply through by factor from the row above
      double denom = U->getElement(i, i);
      for (int j = i + 1; j <= rows; j++)
      {
         double numer = U->getElement(j, i);
         double factor = numer/denom;
         for (int k = i; k <= cols; k++)
         {
            double temp = U->getElement(i, k) * factor;
            double subtract = U->getElement(j, k) - temp;
            U->setElement(j, k, subtract);
         }
         L->setElement(j, i, factor);
      }
      L->setElement(rows, rows, 1.0);
   }

   Matrix** PLU = new Matrix*[3];
   PLU[0] = L;
   PLU[1] = U;
   PLU[2] = P;

   return PLU;
}

Matrix* Matrix::forwardSubstitution(Matrix* colVector)
{  
   int rows = colVector->getNumRows();
   Matrix* result = new Matrix(rows, 1);

   for (int i = 1; i <= rows; i++)
   {
      double rhs = colVector->getElement(i, 1);  
      double coeff = getElement(i, i);
      for (int j = 1; j < i; j++)
      {
         rhs = rhs - getElement(i, j)*result->getElement(j, 1);
      }
      result->setElement(i, 1, rhs/coeff);
   }

   return result;
}

Matrix* Matrix::backSubstitution(Matrix* colVector)
{
   int rows = colVector->getNumRows();
   Matrix* result = new Matrix(rows, 1);

   for (int i = rows; i >= 1 ; i--)
   {
      double rhs = colVector->getElement(i, 1); 
      double coeff = getElement(i, i);
      for (int j = rows; j > i; j--)
      {
         rhs = rhs - getElement(i, j)*result->getElement(j, 1);
      }
      result->setElement(i, 1, rhs/coeff);
   }

   return result;
}

//pivot rows row1 and row2 (swap them)
Matrix* Matrix::pivotRows(int row1, int row2)
{
   int cols = getNumCols();
   for (int i = 1; i <= cols; i++)
   {
      double temp = getElement(row1, i);
      setElement(row1, i, getElement(row2, i));
      setElement(row2, i, temp);
   }
}

Matrix* Matrix::copy()
{
   int rows = getNumRows();
   int cols = getNumCols();
   Matrix* mat = new Matrix(rows, cols);

   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         mat->setElement(i, j, getElement(i, j));
      }
   }

   return mat;
}

Matrix* Matrix::inverse()
{
   Matrix** PLUarray = PLU();
   Matrix* L = PLUarray[0];
   Matrix* U = PLUarray[1];
   Matrix* P = PLUarray[2];
   delete[] PLUarray;

   int rows = getNumRows();
   int cols = getNumCols();

   Matrix* inverse = new Matrix(rows, cols);

   for (int i = 1; i <= cols; i++)
   {
      Matrix* colVector = new Matrix(rows, 1);
      colVector->setElement(i, 1, 1.0);  //basis vectors

      Matrix* temp = L->forwardSubstitution(colVector);
      delete colVector;
      colVector = temp;

      temp = U->backSubstitution(colVector);
      delete colVector;
      colVector = temp;

      for (int j = 1; j <= rows; j++)
      {
         inverse->setElement(j, i, colVector->getElement(j, 1));
      }
      delete colVector;
   }

   delete L;
   delete U;
   Matrix* temp = inverse->multiply(P);
   delete inverse;
   inverse = temp;
   delete P;

   return inverse;
}

//return the Matrix as a column vector of floats for OpenGL
const float* Matrix::toArrayColumnMajor() 
{
   int rows = getNumRows();
   int columns = getNumCols();

   float* mat = new float[rows*columns];
   for (int i = 1; i <= columns; i++)
   {
      for (int j = 1; j <= rows; j++)
      {
         int loc = (i - 1)*columns + (j - 1);
         mat[loc] = (float) getElement(j, i);
      }
   }

   return mat;
}
