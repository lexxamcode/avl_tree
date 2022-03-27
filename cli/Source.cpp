#include <iostream>
#include "../headers/set.h"

int main()
{
	set<int> newset;
	newset.insert(3);
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