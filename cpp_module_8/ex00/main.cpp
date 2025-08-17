#include "include/easyfind.hpp"

int main()
{

	std::vector<int> v;
	v.reserve(100);

	for(int i = 0; i < 100; ++i)
		v.push_back(i);

	std::random_shuffle(v.begin(), v.end());

	int result;

	result = easyfind(v, 31);
	if(result == -42)
		std::cout << "No such item" << std::endl;
	else
		std::cout << "Item found: " << result << std::endl;
	
	result = easyfind(v, 431);
	if(result == -42)
		std::cout << "No such item" << std::endl;
	else
		std::cout << "Item found: " << result << std::endl;


	return 0;
}