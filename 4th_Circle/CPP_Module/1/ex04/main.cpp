#include <iostream>
#include <fstream>
int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::string	inputs[3] = {argv[1], argv[2], argv[3]};
		if (inputs[1].length() <= 0)
		{
			std::cout << "[Error] : the second arg, string s1's length should be longer than 0\n";
			return (1);
		}
		std::ifstream	in(inputs[0]);
		if (in.fail() || in.bad())
		{
			std::cout << "[Error] : something went wrong in file open process\n";
			return (1);
		}
		else if (in.is_open())
		{
			in.seekg(0, in.end);
			int	length = in.tellg();
			if (length <= 0)
			{
				std::cout << "Error : The file is empty!\n";
				in.close();
				return (1);
			}
			in.seekg(0, in.beg);
			std::string	wholeText;
			wholeText.resize(length);
			in.read (&wholeText[0], length);
			while (1)
			{
				size_t found = wholeText.find(inputs[1]);
				if (found == std::string::npos)
					break;
				wholeText = wholeText.substr(0, found) + inputs[2] + wholeText.substr(found + inputs[1].length(), -1);
			}
			in.close();

			std::ofstream	ofs;
			ofs.open (inputs[0] + ".replace", std::ofstream::out);
			ofs << wholeText;
			ofs.close();
			return (0);
		}
	}
	else
	{
		std::cout << "invalid argc : " << argc << "\n[usage] : ./a.out filename string1 string2\n";
		return (1);
	}
}
