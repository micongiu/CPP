#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>

class Span
{
	private:
		std::vector<int> _numbers;
		size_t	_size;

	public:
		Span( unsigned int N );
		Span( const Span &src );
		Span& operator=( const Span &src );
		~Span();

		void addNumber(int toAdd);
		int shortestSpan();
		int longestSpan();

		class NoElementFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class MaxNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif