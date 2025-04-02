#include "include/Zombie.hpp"

int main()
{
	Zombie *horde;
	std::string name;
	int N;

	N = 5;
	name = "Harold";
	horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
}
