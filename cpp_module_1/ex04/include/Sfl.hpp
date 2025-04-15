#ifndef SFL_HPP
#define SFL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Sfl
{
	private:
		std::string _inFile;
		std::string _outFile;

	public:
		Sfl( std::string filename );
		~Sfl();

	void replace( std::string s1, std::string s2);
};

#endif