/*
File Name: CSC161_jjordan_ProgrammingChal2.cpp
Author: Josh Jordan
Date: 2/22/2021
Description:

Notes:
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>

class inventory
{
public:

	/****************
	 * CONSTRUCTORS *
	 ****************/

	inventory() //default constructor
	{
		SerialNum = 0123;
		ManufactureDate = "01/12/23";
		LotNum = 01;
	}

	inventory(int serialNum, std::string manufactureDate, int lotNum)
	{
		serialNum = SerialNum;
		manufactureDate = ManufactureDate;
		lotNum = LotNum;
	}


	/***********
	 * GETTERS *
	 ***********/

	int get_SerialNumber()
	{
		return SerialNum;
	}

	std::string get_ManufactureDate()
	{
		return ManufactureDate;
	}
	int get_LotNum()
	{
		return LotNum;
	}


	/***********
	 * SETTERS *
	 ***********/

	void set_SerialNumber(int serialNum)
	{
		SerialNum = serialNum;
	}

	void set_ManufactureDate(std::string manufactureDate)
	{
		ManufactureDate = manufactureDate;
	}
	void set_LotNum(int lotNum)
	{
		LotNum = lotNum;
	}

private:
	int SerialNum;
	std::string ManufactureDate;
	int LotNum;
};



/******************
 * MAIN FUNCTIONS *
 ******************/

void print_FirstMenu()
{
	std::cout << "----- Menu -----" << std::endl;
	std::cout << "1) Stack" << std::endl;
	std::cout << "2) Queue" << std::endl;
	std::cout << "3) Exit" << std::endl;
}

void print_StackMenu()
{
	std::cout << "----------------- STACK -----------------" << std::endl;
	std::cout << "1) Add a part to inventory" << std::endl;
	std::cout << "2) Remove most recent part from inventory" << std::endl;
	std::cout << "3) View inventory" << std::endl;
	std::cout << "4) Exit" << std::endl;
}

void print_QueueMenu()
{
	std::cout << "----------------- QUEUE -----------------" << std::endl;
	std::cout << "1) Add a part to inventory" << std::endl;
	std::cout << "2) Remove most recent part from inventory" << std::endl;
	std::cout << "3) View inventory" << std::endl;
	std::cout << "4) Exit" << std::endl;
}

int main()
{
	int FirstMenu, SecondMenu, SerialNum, LotNum;
	std::string ManufactureDate;
	inventory StackPart;
	std::stack<inventory> stack;
	std::queue<inventory> queue;

	print_FirstMenu();
	std::cin >> FirstMenu;

	while (FirstMenu > 0 && FirstMenu < 3) // choosing between stack or queue
	{
		if (FirstMenu == 1) // stack was chosen
		{
			print_StackMenu();
			std::cin >> SecondMenu;
			while (SecondMenu > 0 && SecondMenu < 4)
			{
				if (SecondMenu == 1) // adding a part to a stack
				{
					std::cout << "Enter the serial number of the part you would like to enter.\n> ";
					std::cin >> SerialNum;
					std::cout << "Enter the date the part was manufactured (XX/XX/20XX).\n> ";
					std::cin >> ManufactureDate;
					std::cout << "Enter the lot number where the part is stored.\n> ";
					std::cin >> LotNum;

					//StackPart(SerialNum, ManufactureDate, LotNum); // constructing information to 'inventory object'
					stack.push(StackPart);
				}
				else if (SecondMenu == 2) // removing the most recent part from the stack
				{

				}
				else if (SecondMenu == 3) // viewing all parts in the stack
				{

				}
			}
		}
		else
		{
			print_QueueMenu();
			std::cin >> SecondMenu;
			while (SecondMenu > 0 && SecondMenu < 4)
			{
				if (SecondMenu == 1) // adding a part to the queue
				{
					std::cout << "Enter the serial number of the part you would like to enter.\n> ";
					std::cin >> SerialNum;
					std::cout << "Enter the date the part was manufactured (XX/XX/20XX).\n> ";
					std::cin >> ManufactureDate;
					std::cout << "Enter the lot number where the part is stored.\n> ";
					std::cin >> LotNum;
				}
				else if (SecondMenu == 2) // removing the first part from the queue
				{

				}
				else if (SecondMenu == 3) // viewing all parts in the queue
				{

				}
			}
		}
	}
	std::cout << "Exiting..." << std::endl;
}