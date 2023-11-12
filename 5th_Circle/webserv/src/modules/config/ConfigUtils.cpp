#include "ConfigUtils.hpp"

// public **********************************************************************

/**
 * @brief Print vector name and its element.
 * For example, when the vector name is fruit_basket and the elements are
 * "apple", "banana", "orange", the printed result will be like this.
 * fruit_basket        : [ apple ] [ banana ] [ orange ]
 *
 * @param vector_name
 * @param str_vector
 */
void ConfigUtils::PrintStringVector(
    const std::string &vector_name,
    const std::vector<std::string> &str_vector) {
  std::cout << std::left << std::setw(kVectorNameSpan) << vector_name << " : ";
  for (size_t i = 0; i < str_vector.size(); i++) {
    std::cout << "[" << str_vector[i] << "] ";
  }
  std::cout << std::endl;
}


/**
 * @brief Returns formatted error message. if message(arg3) is NULL, it will
 * print "Error in this line" at the next line.
 *
 * @param message
 * @param error_line
 * @return std::string
 */
std::string ConfigUtils::MakeErrorMessage(size_t error_line_number,
                                       const std::string error_line,
                                       const char *message) {
  std::stringstream ss;
  std::cout << std::endl;
  ss << "Error :" << error_line_number << ":" << error_line << "\n  ";
  if (message == NULL)
    ss << "Error in this line!!";
  else
    ss << message;
  if (kColorErrorMessage)
    return MyString::ColorString(ss.str(), kStrRed, kStrBlack);
  else
    return ss.str();
}


// private *********************************************************************
