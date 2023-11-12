/**
 * @file ConfigTest.cpp
 * @author Jun (syo2357@gmail.com)
 * @brief How to use this test file
 * 1. Move this file to src/modules/config
 * 2. Remove any other files from src folder except files in modules/config and
 *    modules/utils
 * 3. type make run to terminal
 * @version 0.1
 * @date 2023-05-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "../../utils/CustomException.hpp"
#include "Config.hpp"

int main(int argc, char** argv) {
  Config configuration;
  try {
    configuration.ParseConfigurationFile(argc, argv);
    configuration.PrintResult();
  } catch (const CustomException& e) {
    std::cerr << e.What() << '\n';
  }
}
