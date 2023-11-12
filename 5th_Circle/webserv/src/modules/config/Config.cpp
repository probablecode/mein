#include "Config.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  constructor
Config::Config() {}

//  constructor with arguments
Config::Config(int argc, char **argv) { ParseConfigurationFile(argc, argv); }

//  copy constructor
Config::Config(const Config &src) { *this = src; }

//  operators ------------------------------------------------------------------

//  =operator overloading
Config &Config::operator=(const Config &rhs) {
  if (this == &rhs) return *this;
  this->server_configs_ = rhs.server_configs_;
  return *this;
}

//  functions ------------------------------------------------------------------

/**
 * @brief The main function of this Class!! This function reads the
 * configuration file. If error occurs, this function will throw an error.
 * Therefore, this should be use in try-catch statement.
 *
 * @param argc
 * @param argv
 */
void Config::ParseConfigurationFile(int argc, char **argv) {
  // Check argument count and open config.conf to read.
  std::ifstream file;
  if (argc == 1)
    file.open(CONFIG_FILE_LOCATION);
  else if (argc == 2)
    file.open(argv[1]);
  else
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "Invalid argc");

  // Check if the file is opened successfully.
  if (file.is_open() == false)
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "File open fail");

  // Validity check in file scope
  CheckBlockValidity(file, kBlockStart, kBlockEnd);
  CheckLineEdges(file);
  CheckTabs(file);
  // TODO : ANY MORE IDEAS?

  // Parse server configs
  std::string line;
  size_t line_cnt = 0;
  while (std::getline(file, line)) {
    line_cnt++;
    if (line.size() > 0 && MyString::GetFirstWord(line, ' ') == "server")
      server_configs_.push_back(ServerConfig(file, line_cnt));
  }

  // Print status message
  if (kPrintProgressMessage)
    std::cout << MyString::ColorString("Parsed a whole configuration file!",
                                       kStrBlue, kStrBlack)
              << std::endl;
}

void Config::PrintResult() const {
  std::cout << MyString::ColorString("Printing parsed result", kStrBlack,
                                     kStrBlue)
            << std::endl;
  for (size_t i = 0; i < server_configs_.size(); i++) {
    server_configs_[i].PrintResult();
  }
}

int Config::GetServerConfigsNum() const {
  return server_configs_.size();
}

const ServerConfig& Config::GetServerConfig(int server_config_idx) const{
  return server_configs_.at(server_config_idx);
}

// private *********************************************************************

//  functions ------------------------------------------------------------------

/**
 * @brief Checks Block Validity in file level. If there is a invalid bock,
 * exception will be thrown.
 *
 * @param file
 * @param block_start
 * @param block_end
 */
void Config::CheckBlockValidity(std::ifstream &file, char block_start,
                                char block_end) const {
  // Every block edges will be saved here.
  std::vector<char> block_edge_stack;

  // Buffer to save a single character. get() will save character here.
  char single_character_buffer;

  while (file.get(single_character_buffer)) {
    if (single_character_buffer == block_start)
      block_edge_stack.push_back(single_character_buffer);
    else if (single_character_buffer == block_end) {
      if (block_edge_stack.size() == 0)
        throw CustomException(CustomException::kExceptionConfigParsing,
                              "Invalid code block");
      else if (block_edge_stack.back() == block_start)
        block_edge_stack.pop_back();
      else
        block_edge_stack.push_back(single_character_buffer);
    }
  }
  if (block_edge_stack.size() != 0)
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "Invalid code block");

  // Clear EOF flag and reset file pointer
  if (file.eof()) {
    file.clear();
    file.seekg(0, std::ios::beg);
  } else
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "CheckBlocValidity did not proceeded till the end");
  if (kPrintProgressMessage)
    std::cout << MyString::ColorString("Passed Block Validity check!", kStrBlue,
                                       kStrBlack)
              << std::endl;
}

/**
 * @brief Checks the line Edges.
 * When the line is not an empty line
 *  1. Comment sign should be the first character of it's line.
 *  2. Except comment line, all lines should have to end with ';' or '{' or '}'.
 * Any other cases will be treated as an error and exception will be thrown.
 *
 * @param file
 */
void Config::CheckLineEdges(std::ifstream &file) const {
  std::string line;
  size_t line_count = 0;
  while (std::getline(file, line)) {
    line_count++;
    if (line.size() > 0) {
      // When the line is not an empty line
      if (line.find(kCommentSign) != std::string::npos) {
        // When the line has a comment sign
        if (line.front() != kCommentSign) {
          // When the comment sign is not the start of the line
          throw CustomException(
              CustomException::kExceptionConfigParsing,
              ConfigUtils::MakeErrorMessage(
                  line_count, line,
                  "Comment sign should be at the start of the line."));
        }
      } else {
        // Line should be end with ';' or '{' or '}'
        if (!(line.back() == kBlockStart || line.back() == kBlockEnd ||
              line.back() == ';'))
          throw CustomException(CustomException::kExceptionConfigParsing,
                                ConfigUtils::MakeErrorMessage(line_count, line));
      }
    }
  }

  // Clear EOF flag and reset file pointer
  if (file.eof()) {
    file.clear();
    file.seekg(0, std::ios::beg);
  } else
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "CheckLineEdges did not proceeded till the end");
  if (kPrintProgressMessage)
    std::cout << MyString::ColorString("Passed Line Edge check!", kStrBlue,
                                       kStrBlack)
              << std::endl;
}

void Config::CheckTabs(std::ifstream &file) const {
  std::string line;
  size_t line_count = 0;
  while (std::getline(file, line)) {
    line_count++;
    if (line.find('\t') != std::string::npos)
      throw CustomException(
          CustomException::kExceptionConfigParsing,
          ConfigUtils::MakeErrorMessage(line_count, line,
                                     "Tab existing!! There should be no tab!"));
  }
  // Clear EOF flag and reset file pointer
  if (file.eof()) {
    file.clear();
    file.seekg(0, std::ios::beg);
  } else
    throw CustomException(CustomException::kExceptionConfigParsing,
                          "CheckTabs did not proceeded till the end");
  if (kPrintProgressMessage)
    std::cout << MyString::ColorString("Passed Tab existence check!", kStrBlue,
                                       kStrBlack)
              << std::endl;
}

/**
 * @brief It just print(in another color) the whole file by using getline.
 *
 * @param file
 * @param use_colored_str
 */
void Config::TestPrint(std::ifstream &file, bool use_colored_str) const {
  // Print the whole file.
  std::string line;
  while (std::getline(file, line)) {
    if (use_colored_str)
      std::cout << MyString::ColorString(line, kStrCyan, kStrBlack)
                << std::endl;
    else
      std::cout << line << std::endl;
  }
  file.close();
}
