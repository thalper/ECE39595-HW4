#include <iostream>
#include <cstdlib>
#include "Array2D.h"

// This constructor is delegated to by other constructors and does all of the 
// allocation, showing an example of a delegating constructor..  
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {
   ary = new int*[numRows];
   for (int i = 0; i < numRows; i++) {
      ary[i] = new int[numCols];
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

Array2D::Array2D(const Array2D& other) : Array2D(other.getNumRows(), other.getNumCols(), 'c') {
   for (int i = 0; i < other.getNumRows(); i++) {
      for (int j = 0; j < other.getNumCols(); j++) {
            this->ary[i][j] = other(i, j);
      }
   }
}

int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

Array2D& Array2D::operator=(Array2D& other) {
   this->deleteAry(this->ary); 

   this->ary = new int*[other.getNumRows()];
   for (int i = 0; i < other.getNumRows(); i++) {
      this->ary[i] = new int[other.getNumCols()];
      for (int j = 0; j < other.getNumCols(); j++) {
            this->ary[i][j] = other(i,j);
      }
   }
   return *this;
   }

bool Array2D::operator==(Array2D& other) {
   if (this->sameSize(other)) 
   {
      for (int i = 0; i < this->getNumRows(); i++) 
      {
         for (int j = 0; j < this->getNumCols(); j++) {
            if (this->ary[i][j] != other.ary[i][j])
               return false;
         }
      }
      return true;
   }
   else
      return false;
}

Array2D Array2D::operator*(Array2D& other) {
   if (this->getNumCols() != other.getNumRows()) {
      Array2D res(this->getNumRows(), this->getNumCols(), 'c');
      return res;
   }

   Array2D res(this->getNumRows(), other.getNumCols(), 0);
   for (int i = 0; i < res.getNumRows(); i++)
   {
      for (int j = 0; j < res.getNumCols(); j++)
      {
         for (int k = 0; k < this->getNumCols(); k++)
         {
            res.ary[i][j] += (this->ary[i][k])*(other.ary[k][j]);
         }
      }
   }

   return res;
}

std::ostream& operator<<(std::ostream& output, Array2D& other) {   
   for (int i = 0; i < other.getNumRows(); i++) {
      for (int j = 0; j < other.getNumCols(); j++) {
         output << other(i, j);
         output << " ";
      }
      output << "\n";
   }
   return output;
}

int Array2D::getNumRows() const {
   return numRows;
}

int Array2D::getNumCols() const {
   return numCols;
}
bool Array2D::sameSize(const Array2D& other) const {
   return (this->getNumRows() == other.getNumRows( ) && this->getNumCols() == other.getNumCols( ));
}

Array2D::~Array2D() {
   this->deleteAry(this->ary);
}

void Array2D::deleteAry(int** ary) {
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}
