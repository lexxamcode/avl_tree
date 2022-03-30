#include <iostream>

#include "../headers/set.h"

int getKey()
{
	return 0;
}

int typeChooseMenu()
{
	std::cout << "\nAVL TREE\n" << std::endl;
	return getKey();
}

int main()
{
	//cli interface;
	//tests
	//graphics
	//||||||| To be done!

	typeChooseMenu();
	set<int> newset;
	newset.insert(3);
	newset.insert(-1);
	newset.insert(1);
	newset.insert(0);
	newset.insert(2);
	newset.insert(4);
	set<int> secset(newset);
	secset.print();
	std::cout << std::endl;
	newset.insert(0);
	newset.print();
	std::cout << std::endl;
	std::cout << newset.find(2) << std::endl;
	newset.erase(1);
	std::cout << std::endl;
	newset.print();
	return 0;
}