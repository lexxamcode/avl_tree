#include <iostream>
#include <math.h>
#include <ctime>
#include <conio.h>
#include <termcolor/termcolor.hpp>
#include "../headers/set.h"
#include <string>

int getKey()
{
	int key = getch();
	return key;
}
int typeChooseMenu(size_t arrow)
{
	std::cout << termcolor::bright_yellow << "AVL TREE\n" << std::endl;
	std::cout << termcolor::white << "Select type:\n" << std::endl;
	
	switch (arrow)
	{
	case 1:
		{
			std::cout << termcolor::bright_blue << "int" << std::endl;
			std::cout << termcolor::white << "float" << std::endl;
			std::cout << termcolor::white << "double" << std::endl;
			break;
		}
	case 2:
		{
			std::cout << termcolor::white << "int" << std::endl;
			std::cout << termcolor::bright_blue << "float" << std::endl;
			std::cout << termcolor::white << "double" << std::endl;
			break;
		}
	case 3:
	{
		std::cout << termcolor::white << "int" << std::endl;
		std::cout << termcolor::white << "float" << std::endl;
		std::cout << termcolor::bright_blue << "double" << std::endl;
		break;
	}
	default:
		break;
	}
	
	int control = getKey();
	if (control == 72 || control == 80 || control == 13 || control == 27)
		return control;
}
int intTreeMenu(size_t arrow, set<int>& iset)
{
	std::cout << termcolor::bright_yellow << "Your " << termcolor::bright_cyan << "int" << termcolor::bright_yellow << " tree:" << termcolor::reset << std::endl;
	iset.print();
	std::cout << std::endl;

	switch (arrow)
	{
	case 1:
	{
		std::cout << termcolor::bright_blue << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::bright_blue << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::bright_blue << "find element" << std::endl;
		break;
	}
	default:
		break;
	}

	int control = getKey();
	if (control == 72 || control == 80 || control == 13 || control == 27)
		return control;
}
int floatTreeMenu(size_t arrow, set<float>& fset)
{
	std::cout << termcolor::bright_yellow << "Your " << termcolor::bright_cyan << "float" << termcolor::bright_yellow << " tree:" << termcolor::reset << std::endl;
	fset.print();
	std::cout << std::endl;

	switch (arrow)
	{
	case 1:
	{
		std::cout << termcolor::bright_blue << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::bright_blue << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::bright_blue << "find element" << std::endl;
		break;
	}
	default:
		break;
	}

	int control = getKey();
	if (control == 72 || control == 80 || control == 13 || control == 27)
		return control;
}
int doubleTreeMenu(size_t arrow, set<double>& dset)
{
	std::cout << termcolor::bright_yellow << "Your " << termcolor::bright_cyan << "double" << termcolor::bright_yellow << " tree:" << termcolor::reset << std::endl;
	dset.print();
	std::cout << std::endl;

	switch (arrow)
	{
	case 1:
	{
		std::cout << termcolor::bright_blue << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::bright_blue << "delete element" << std::endl;
		std::cout << termcolor::white << "find element" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << termcolor::white << "add element" << std::endl;
		std::cout << termcolor::white << "delete element" << std::endl;
		std::cout << termcolor::bright_blue << "find element" << std::endl;
		break;
	}
	default:
		break;
	}

	int control = getKey();
	if (control == 72 || control == 80 || control == 13 || control == 27)
		return control;
}
int getInt()
{
	int value;
	char str[256];
	while (true)
	{
		system("cls");
		std::cout << termcolor::bright_cyan << "Enter a value:" << std::endl;

		try
		{
			gets_s(str, 256);
			value = std::stoi(str);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid argument.";
			system("pause");
		}

	}
	return value;
}
float getFloat()
{
	float value;
	char str[256];
	while (true)
	{
		system("cls");
		std::cout << termcolor::bright_cyan << "Enter a value:" << std::endl;

		try
		{
			gets_s(str, 256);
			value = std::stof(str);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid argument.";
			system("pause");
		}

	}
	return value;
}
double getDouble()
{
	double value;
	char str[256];
	while (true)
	{
		system("cls");
		std::cout << termcolor::bright_cyan << "Enter a value:" << std::endl;

		try
		{
			gets_s(str, 256);
			value = std::stod(str);
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid argument.";
			system("pause");
		}

	}
	return value;
}
void process()
{
	set<int> intset;
	set<float> floatset;
	set<double> doubleset;

	int arrow = 1;
	while (true)
	{
		system("cls");
		int choose_type = typeChooseMenu(arrow);
		if (choose_type == 27)
			return;
		else if (choose_type == 13)
		{
			if (arrow == 1)
			{
				while (true)
				{
					system("cls");
					int tree_function = intTreeMenu(arrow, intset);
					if (tree_function == 27)
					{
						arrow = 1;
						break;
					}
					else if (tree_function == 13)
					{
						int value = getInt();
						if (arrow == 1)
							intset.insert(value);
						else if (arrow == 2)
							intset.erase(value);
						else if (arrow == 3)
						{
							if (intset.find(value))
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " exists in the tree" << std::endl;
								system("pause");
							}
							else
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " does not exist in the tree" << std::endl;
								system("pause");
							}
						}
					}
					else if (tree_function == 72 && arrow > 1)
						arrow--;
					else if (tree_function == 80 && arrow < 3)
						arrow++;
				}
			}
			else if (arrow == 2)
			{
				arrow = 1;
				while (true)
				{
					system("cls");
					int tree_function = floatTreeMenu(arrow, floatset);
					if (tree_function == 27)
					{
						arrow = 1;
						break;
					}
					else if (tree_function == 13)
					{
						float value = getFloat();
						if (arrow == 1)
							floatset.insert(value);
						else if (arrow == 2)
							floatset.erase(value);
						else if (arrow == 3)
						{
							if (floatset.find(value))
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " exists in the tree" << std::endl;
								system("pause");
							}
							else
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " does not exist in the tree" << std::endl;
								system("pause");
							}
						}
					}
					else if (tree_function == 72 && arrow > 1)
						arrow--;
					else if (tree_function == 80 && arrow < 3)
						arrow++;
				}
			}
			else if (arrow == 3)
			{
				arrow = 1;
				while (true)
				{
					system("cls");
					int tree_function = doubleTreeMenu(arrow, doubleset);
					if (tree_function == 27)
					{
						arrow = 1;
						break;
					}
					else if (tree_function == 13)
					{
						double value = getDouble();
						if (arrow == 1)
							doubleset.insert(value);
						else if (arrow == 2)
							doubleset.erase(value);
						else if (arrow == 3)
						{
							if (doubleset.find(value))
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " exists in the tree" << std::endl;
								system("pause");
							}
							else
							{
								system("cls");
								std::cout << termcolor::bright_cyan << value << termcolor::reset << " does not exist in the tree" << std::endl;
								system("pause");
							}
						}
					}
					else if (tree_function == 72 && arrow > 1)
						arrow--;
					else if (tree_function == 80 && arrow < 3)
						arrow++;
				}
			}
		}
		else if (choose_type == 80 && arrow < 3)
			arrow++;
		else if (choose_type == 72 && arrow > 1)
			arrow--;
	}
}

int main()
{
	process();
	return 0;
}