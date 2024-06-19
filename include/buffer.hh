

#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <vector>
#include <string>
#include <codecvt>
#include <locale>

#include "json_tree.hh"

class StringBuffer {
private:
  std::vector<std::vector<std::string>> _buffer;
  std::vector<bool> _flag_table;

public:
  //! @brief Add a empty line
  //! 
  void addLine();

  //! @brief Add a new line
  void addLine(const std::vector<std::string>& newLine);

  //! @brief Add a string into buffer, specify the line number
  //! 
  //! @param rowIdx The line number
  //! @param str The string to add
  void addString(int rowIdx, const std::string& str);

  //! @brief Replace a string in one line, specify the (row, col) location
  //! 
  //! @param rowIdx The line number
  //! @param colIdx The indx of a string in one line
  //! @param str The new string to write
  void replaceString(int rowIdx, int colIdx, const std::string& str);

  void replaceString(int rowIdx, int colIdx, const std::string& oldStr, const std::string& newStr) {
    auto& str = _buffer[rowIdx][colIdx];
    size_t startPos = 0;
    while ((startPos = str.find(oldStr, startPos)) != std::string::npos) {
      str.replace(startPos, oldStr.length(), newStr);
      startPos += newStr.length(); // 移动到新字符串的后面，避免循环替换
    }
  }

  //! @brief Clear the whole buffer
  //! 
  void clear() { _buffer.clear(); }

  //! @brief Print the whole buffer
  //! 
  void print(); 


  //! @SizeAccessor {

  //! @brief Get the number of lines of the whole buffer
  //! 
  int size() { return _buffer.size(); }

  //! @brief Get the number of string of a specified line.
  //! 
  int size(int rowIdx);
  
  //! @brief Count the number of char of a specified line.
  //! 
  int length(int rowIdx);

  //! @ }


  //! @ExceptionChecker {
  
  //! @brief Check if the rowIdx out of range
  //!
  void check(int rowIdx);

  //! @brief Check if the (rowIdx, colIdx) out of range
  //!
  void check(int rowIdx, int colIdx);


  //! @FlagMarker {

  //! @brief Mark a line with specified flag
  //! 
  void mark(int rowIdx, bool flag);

  //! @brief Check if a flag is true?
  //! 
  bool isMarked(int rowIdx);

  //! @ }
};


#endif // BUFFER_H