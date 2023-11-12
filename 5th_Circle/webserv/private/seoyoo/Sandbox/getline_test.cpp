#include <iostream>
#include <string>
#include <fstream>

int main(void) {
  std::ifstream file;
  file.open("file_to_read.txt");
  if (!file.is_open())
    std::cout << "File open failed" << std::endl;
  std::string line;
  while (getline(file, line)) {
    std::cout << "line.size() : " << line.size() << std::endl;
  }
}