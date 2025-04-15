#include "../include/Sfl.hpp"

Sfl::Sfl( std::string filename ) : _inFile( filename )
{
	this->_outFile = this->_inFile + ".replace";
}

Sfl::~Sfl ( void )
{

}

void Sfl::replace( std::string s1, std::string s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty search or replace string." << std::endl;
		exit(-1);
	}

	std::ifstream inputFile(this->_inFile.c_str());

	if(!inputFile)
	{
		std::cout << "Error: Could not open file: " << this->_inFile << std::endl;
		exit(-1);
	}

	std::string line;
	std::string content;

	while(std::getline(inputFile, line))
		content += line + "\n";

	std::size_t found;
	std::size_t pos = 0;
	std::string output;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		output += content.substr(pos, found - pos) + s2;
		pos = found + s1.length();
	}
	output += content.substr(pos);

	std::ofstream outFile(this->_outFile.c_str());
	if (!outFile)
	{
		std::cout << "Error: Could not create output file: " << this->_outFile << std::endl;
		exit(-1);
	}

	outFile << output;
	outFile.close();
}