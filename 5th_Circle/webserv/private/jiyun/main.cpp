#include <iostream>
#include "Webserv.hpp"

int	main(int argc, char *argv[]) {
  Config config;
  try {
	config.ParseConfigurationFile(argc, argv);
	config.PrintResult();
  } catch (const CustomException& e) {
	std::cerr << e.What() << '\n';
  }

  Webserv webserv(config);

  std::cout << "hello this is main\n";
  return 0;
}