#include <iostream>
#include <string>
#include <sstream>
#include "OthelloMove.h"
#include "OthelloExceptions.h"

using namespace std;

int OthelloMove::mOnHeap = 0;
const int MAX_SIZE = 8;

OthelloMove::OthelloMove()
   : mRow(-1), mCol(-1)
{
}

OthelloMove::OthelloMove(int row, int col)
   : mRow(row), mCol(col)
{
}

OthelloMove& OthelloMove::operator=(const std::string &move) {
   if (move == "pass") {
      mRow = -1;
      mCol = -1;
      return *this;
   }
   else {
      istringstream s(move);
      char junk;
      s >> junk >> mRow >> junk >> mCol >> junk;
      if (mRow >= MAX_SIZE || mRow < 0 || mCol >= MAX_SIZE || mCol < 0) {
         throw OthelloException("out of bounds");
      }
      return *this;
   }
}

bool operator==(const OthelloMove &lhs, const OthelloMove &rhs) {
   if (lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol) {
      return true;
   }
   return false;
}

OthelloMove::operator std::string() const {
   if (mRow !=-1 && mCol !=-1) {
      ostringstream s;
      s << "(" << mRow << ", " << mCol << ")";
      return s.str();
   }
   return "pass";
}
