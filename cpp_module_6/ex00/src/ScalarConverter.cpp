#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

void ScalarConverter::convert(std::string toConvert)
{
	if (specialCases(toConvert))
		return;

	if (toConvert.length() == 1 || isQuotedChar(toConvert))
		if (charCase(toConvert))
			return;

	if (intCase(toConvert))
		return;

	if (floatCase(toConvert))
		return;

	if (doubleCase(toConvert))
		return;

	std::cout << "char: impossible\n" << "int: impossible\n" << "float: impossible\n" << "double: impossible\n" << std::endl;
}

int specialCases(const std::string &toConvert)
{
	if (toConvert != "nan" and toConvert != "nanf" and toConvert != "-inf" and toConvert != "+inf" and toConvert != "-inff" and toConvert != "+inff")
		return (0);

	std::cout << "char: impossible\n" << "int: impossible" << std::endl;

	// from double to float
	if (toConvert == "nan" || toConvert == "-inf" || toConvert == "+inf")
		std::cout << "float: " << toConvert << "f\n" << "double: " << toConvert << std::endl;
	else // from float to double
		std::cout << std::fixed << std::setprecision(1) << "float: " << toConvert << "\ndouble: " << toConvert.substr(0, toConvert.length() - 1) << std::endl;
	return (1);
}

bool isQuotedChar(const std::string &toConvert)
{
	return (toConvert.length() == 3 && toConvert[0] == '\'' && toConvert[2] == '\'');
}

int charCase(const std::string &toConvert)
{
	std::string str = toConvert;
	bool isQuoted = isQuotedChar(toConvert);

	if (isQuoted)
		str = toConvert.substr(1, 1);

	char c = str[0];

	if (!std::isprint(static_cast<unsigned char>(c)))
		return (0);

	if (std::isdigit(c) && !isQuoted)
		return (intCase(str));

	double value = static_cast<double>(c);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int intCase(const std::string &toConvert)
{
	char *end;
	long num = std::strtol(toConvert.c_str(), &end, 10);

	if (*end != '\0')
		return (0);

	if (errno == ERANGE || num < INT_MIN || num > INT_MAX)
		return (0);

	double value = static_cast<double>(num);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int floatCase(const std::string &toConvert)
{
	char *end;
	float num = std::strtof(toConvert.c_str(), &end);

	if (end[0] != 'f' || end[1] != '\0')
		return (0);

	if (errno == ERANGE)
		return (0);

	double value = static_cast<double>(num);
	printChar(value);
	printInt(value);
	printFloatDouble(value);

	return (1);
}

int doubleCase(const std::string &toConvert)
{
	char *end;
	double num = std::strtod(toConvert.c_str(), &end);

	if (*end != '\0')
		return (0);

	if (errno == ERANGE)
		return (0);

	printChar(num);
	printInt(num);
	printFloatDouble(num);

	return (1);
}

void printChar(double value)
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void printInt(double value)
{
	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloatDouble(double value)
{
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f\ndouble: " << value << std::endl;
}