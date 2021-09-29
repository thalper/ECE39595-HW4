#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 
   Array2D(const Array2D& other); 

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;
   Array2D& operator=(Array2D& other);
   bool operator==(Array2D& other);
   Array2D operator*(Array2D& other);
   friend std::ostream& operator<<(std::ostream& output, Array2D& other);
   ~Array2D();

   int numRows;
   int numCols;
   int** ary;

private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;
   int getNumRows() const;
   int getNumCols() const;
};
#endif /* ARRAY2D_H_ */
