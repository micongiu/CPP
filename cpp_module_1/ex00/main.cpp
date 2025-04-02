#include "include/Zombie.hpp"

int main()
{
	std::cout << "-->Creating a Zombie on the stack:<--" << std::endl;
	Zombie zombie;
	zombie.announce();
	randomChump("Jacob");

	std::cout << std::endl << "-->Creating a Zombie on the heap:<--" << std::endl;
	Zombie *heapZombie; 
	Zombie *heapZombie2;
	heapZombie = new Zombie("Heapy");
	heapZombie->announce();
	heapZombie2 = newZombie("Harold");
	heapZombie2->announce();
	delete heapZombie;
	delete heapZombie2;

	return 0;
}
