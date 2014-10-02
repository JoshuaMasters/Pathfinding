#include "Pathfinding.hpp"
#include <iostream>

int main()
{
	char a;
	Pathfinding path({9, 9});

	path.findPath({0, 0}, {9, 9});

	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			std::cout << path.getNodeValue({i, j});
		}
		std::cout << std::endl;
	}
	std::cin >> a;

	return(0);
}
