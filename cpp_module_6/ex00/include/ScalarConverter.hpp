#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstdlib>
# include <climits>
# include <limits>
# include <cerrno>
# include <cctype>
# include <iomanip>
# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);

	public:
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &src);

		// Methods
		static void convert(std::string literal);
};

// Helper Functions
int charCase(const std::string &literal);
int intCase(const std::string &literal);
int floatCase(const std::string &literal);
int doubleCase(const std::string &literal);
int specialCases(const std::string &literal);
bool isQuotedChar(const std::string &literal);

// Print Functions
void printChar(double value);
void printInt(double value);
void printFloatDouble(double value);

#endif