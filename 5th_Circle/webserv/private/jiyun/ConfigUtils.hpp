#ifndef CONFIGUTILS_HPP_
#define CONFIGUTILS_HPP_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "utils/MyString.hpp"

class ConfigUtils {
 public:
  static void PrintStringVector(const std::string &vector_name,
                                const std::vector<std::string> &str_vector);
  static std::string MakeErrorMessage(size_t error_line_number,
                                      const std::string error_line,
                                      const char *message = NULL);

 private:
  // constructors & destructor
  ConfigUtils() {}
  // constants
  static const int kVectorNameSpan = 17;
  static const bool kColorErrorMessage = true;
};

#endif