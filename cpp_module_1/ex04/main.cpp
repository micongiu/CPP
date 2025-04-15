#include "include/Sfl.hpp"

int main( int argc, char** argv )
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./SedV2 <filename> <to_find> <replace>." << std::endl;
		exit(-1);
	}
	else
	{
		Sfl sfl(argv[1]);
		sfl.replace(argv[2], argv[3]);
	}

	return 0;
}
