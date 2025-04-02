#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Launch the program with: ./Losers <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);

	if(!inputFile)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return 3;
	}

	std::string content;
	std::string line;

	while(std::getline(inputFile, line))
		content += line + "\n";
	
	std::size_t found;
	if ((found = content.find(s1)) != std::string::npos)
	{
		std::cout << "Found: " << found << '\n';
	}
	
	std::ofstream outFile((std::string(argv[1]) + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return 4;
	}

	outFile << content;
	outFile.close();

	return 0;
}
