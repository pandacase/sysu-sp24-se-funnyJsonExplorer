
#include "buffer.hh"


void
StringBuffer::addLine() 
{
  _buffer.push_back(std::vector<std::string>()); 
  _flag_table.push_back(false);
}

void
StringBuffer::addLine(const std::vector<std::string>& newLine) 
{
  _buffer.push_back(newLine); 
  _flag_table.push_back(false);
}



void
StringBuffer::addString(int rowIdx, const std::string& str)
{
  check(rowIdx);
  _buffer[rowIdx].push_back(str);
}


void 
StringBuffer::replaceString(int rowIdx, int colIdx, const std::string& str)
{
  check(rowIdx, colIdx);
  _buffer[rowIdx][colIdx] = str;
}


void 
StringBuffer::print()
{
  for (const auto& line : _buffer) {
    for (const auto& str : line) {
      std::cout << str;
    }
    std::cout << std::endl;
  }
}



//////////////////////////////////////////////////////////////////
// @SizeAccessor
//////////////////////////////////////////////////////////////////

int 
StringBuffer::size(int rowIdx)
{
  check(rowIdx);
  return _buffer[rowIdx].size();
}


int
StringBuffer::length(int rowIdx)
{
  int ret = 0;
  for (const auto& str : _buffer[rowIdx]) {
    ret += str.length();
  }
  return ret;
}

//////////////////////////////////////////////////////////////////
// @ExceptionChecker
//////////////////////////////////////////////////////////////////


void
StringBuffer::check(int rowIdx)
{
  if (rowIdx < 0 || rowIdx >= _buffer.size())
    throw std::out_of_range("Row index out of range.");
}

void
StringBuffer::check(int rowIdx, int colIdx)
{
  check(rowIdx);
  if (colIdx < 0 || colIdx >= _buffer[rowIdx].size())
    throw std::out_of_range("Column index out of range.");
}

//////////////////////////////////////////////////////////////////
// @FlagMarker
//////////////////////////////////////////////////////////////////

void
StringBuffer::mark(int rowIdx, bool flag)
{
  check(rowIdx);
  _flag_table[rowIdx] = flag;
}


bool
StringBuffer::isMarked(int rowIdx)
{
  check(rowIdx);
  return _flag_table[rowIdx];
}
