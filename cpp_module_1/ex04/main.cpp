#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void	checkArg(std::string& s1, std::string& s2, int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./stringReplace <filename> <s1> <s2>" << std::endl;
		exit(-1);
	}

	s1 = argv[2];
	s2 = argv[3];

	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty search or replace string." << std::endl;
		exit(-1);
	}
}

void readLine(std::string& content, char* argv_1)
{
	std::ifstream inputFile(argv_1);

	if(!inputFile)
	{
		std::cout << "Error: Could not open file: " << argv_1 << std::endl;
		exit(-1);
	}

	std::string line;

	while(std::getline(inputFile, line))
		content += line + "\n";
}

void replaceLine(std::string& output, std::string content, std::string& s1, std::string& s2)
{
	std::size_t found;
	std::size_t pos = 0;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		output += content.substr(pos, found - pos) + s2;
		pos = found + s1.length();
	}
	output += content.substr(pos);
}

void writeToFile(std::string& output, char* argv_1)
{
	std::ofstream outFile((std::string(argv_1) + ".replace").c_str());
	if (!outFile)
	{
		std::cout << "Error: Could not create output file: " << (std::string(argv_1) + ".replace") << std::endl;
		exit(-1);
	}

	outFile << output;
	outFile.close();
}

int main(int argc, char** argv)
{
	std::string s1;
	std::string s2;
	checkArg(s1, s2, argc, argv);

	std::string content;
	readLine(content, argv[1]);

	std::string output;
	replaceLine(output, content, s1, s2);

	writeToFile(output, argv[1]);

	return 0;
}
