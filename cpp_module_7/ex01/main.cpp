#include "include/iter.hpp"


int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array:" << std::endl;
	iter(arr, len, print<const int>);
	iter(arr, len, increment<int>);
	std::cout << "After incrementing:" << std::endl;
	iter(arr, len, print<const int>);

	std::string strArr[] = {"Hello", "World", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "String array:" << std::endl;
	iter(strArr, strLen, print<const std::string>);

	return 0;
}