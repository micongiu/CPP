#include "include/MutantStack.hpp"
#include <iostream>

int main()
{
		std::cout << "Test the Stack using INT" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(77);
		mstack.push(17);
		std::cout << "print The first element of the stack" << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		
		std::cout << "print The Size of the stack" << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.push(69);
		mstack.push(3);
		mstack.push(777);
		mstack.push(7);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end() - 1;
		std::cout << "print bigin and end of stack using iterators" << std::endl;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "Test if ++ work with iterator" << std::endl;
		++it;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "Test if -- work with iterator" << std::endl;
		--it;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "print The Content of the stack Using iterators" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "size: " << std::endl;
		std::cout << mstack.size() << std::endl;
		std::stack<int> s(mstack);
	}
		std::cout << "Test the Stack using string" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Banana");
		mstack.push("Mela");
		std::cout << "\nprint The first element of the stack" << std::endl;
		std::cout << mstack.top() << std::endl;
		mstack.pop();

		std::cout << "\nsize:" << std::endl;
		std::cout << mstack.size() << std::endl;

		mstack.push("Franco");
		mstack.push("77");
		mstack.push("Intra");
		mstack.push("Ho finito le parole");
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end() - 1;
		std::cout << "print bigin and end of stack using iterators" << std::endl;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		
		std::cout << "\nTest if ++ work with iterator" << std::endl;
		++it;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "\nTest if -- work with iterator" << std::endl;
		--it;
		std::cout << "begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "\nprint The Content of the stack Using iterators" << std::endl;
		
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "\nsize: " << std::endl;
		std::cout << mstack.size() << std::endl;
		std::stack<std::string> s(mstack);
	}
	return 0;
}