#include "../include/span.hpp"

Span::Span( unsigned int N) : _size(N)
{
}

Span::~Span()
{
}

Span::Span(const Span &src) : _numbers(src._numbers), _size(src._size)
{
}

Span &Span::operator=(const Span &src)
{
	if(this != &src) {
		this->_numbers = src._numbers;
		this->_size = src._size;
	}
	return *this;
}

void Span::addNumber(int toAdd)
{
	if (this->_numbers.size() >= this->_size)
		throw Span::MaxNumber();
	
	this->_numbers.push_back(toAdd);
}

int Span::shortestSpan()
{
	if (this->_numbers.empty())
		throw Span::NoElementFound();
	
	std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;

    for (size_t i = 1; i < sorted.size(); ++i) {
        if (sorted[i] - sorted[i-1] < minSpan) {
            minSpan = sorted[i] - sorted[i-1];
        }
    }

	return (minSpan);
}

int Span::longestSpan()
{
	if (this->_numbers.empty())
		throw Span::NoElementFound();
	
	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return (maxVal - minVal);
}

const char*	Span::MaxNumber::what() const throw()
{
	return ("The vector is full");
}

const char* Span::NoElementFound::what() const throw()
{
	return ("The vector is empty");
}