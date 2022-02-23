/*
File Name: CSC161_jjordan_ProgrammingChal2.cpp
Author: Josh Jordan
Date: 2/22/2021
Description: Assignment is to create an 'inventory' class and prompt the user to choose between a stack or a queue and use
both of those abstract data types to manage the inventory. User will input information on the part via prompt.

NOTES: Currently only issue with code is 'exit' option is not exiting the code. This is most likely due to line 120. Although
the code is exiting the way it is supposed to line 120 is reinitializing the menu instead of full breaking from all of the loops.
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>

class inventory
{
public:
	// CONSTRUCTORS //

	inventory() // default constructor
	{
		SerialNum = 0123;
		ManufactureDate = "01/12/23";
		LotNum = 01;
	}

	inventory(int serialNum, std::string manufactureDate, int lotNum)
	{
		set_SerialNum(serialNum);
		set_ManufactureDate(manufactureDate);
		set_LotNum(lotNum);
	}

	
	// GETTERS //

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


	// SETTERS //

	void set_SerialNum(int serialNum)
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



// MAIN FUNCTIONS //

void print_FirstMenu()
{
	std::cout << "----- Menu -----" << std::endl;
	std::cout << "1) Stack" << std::endl;
	std::cout << "2) Queue" << std::endl;
	std::cout << "3) Exit\n> ";
}

void print_StackMenu()
{
	std::cout << "\n----------------- STACK -----------------" << std::endl;
	std::cout << "1) Add a part to inventory" << std::endl;
	std::cout << "2) Remove most recent part from inventory" << std::endl;
	std::cout << "3) View inventory" << std::endl;
	std::cout << "4) Exit\n> ";
}

void print_QueueMenu()
{
	std::cout << "\n----------------- QUEUE -----------------" << std::endl;
	std::cout << "1) Add a part to inventory" << std::endl;
	std::cout << "2) Remove the first part from inventory" << std::endl;
	std::cout << "3) View inventory" << std::endl;
	std::cout << "4) Exit\n> ";
}

int main()
{
	int FirstMenu, SecondMenu, SerialNum, LotNum;
	std::string ManufactureDate;
	inventory part;
	std::stack<inventory> stack;
	std::queue<inventory> queue;

	print_FirstMenu();
	std::cin >> FirstMenu;

	while (FirstMenu > 0 && FirstMenu < 3) // choosing between stack or queue //
	{
		if (FirstMenu == 1) // stack was chosen //
		{
			print_StackMenu();
			std::cin >> SecondMenu;
			while (SecondMenu > 0 && SecondMenu < 4)
			{
				if (SecondMenu == 1) // adding a part to a stack //
				{
					std::cout << "\nEnter the serial number of the part you would like to enter.\n> ";
					std::cin >> SerialNum;

					std::cout << "Enter the date the part was manufactured (XX/XX/20XX).\n> ";
					std::cin >> ManufactureDate;

					std::cout << "Enter the lot number where the part is stored.\n> ";
					std::cin >> LotNum;
					
					part = inventory(SerialNum, ManufactureDate, LotNum); // constructing information to 'inventory object' //
					stack.push(part);
					print_StackMenu();
					std::cin >> SecondMenu;
				}
				else if (SecondMenu == 2) // removing the most recent part from the stack //
				{
					if (stack.size() > 0)
					{
						std::cout << "Serial Number: " << part.get_SerialNumber() << std::endl;
						std::cout << "Manufacture Date: " << part.get_ManufactureDate() << std::endl;
						std::cout << "Lot Number: " << part.get_LotNum() << std::endl;
						
						stack.pop();

						std::cout << "\nPart has been removed..." << std::endl;

						print_StackMenu();
						std::cin >> SecondMenu;
					}
					else // if no items are in the stack to remove //
					{
						std::cout << "Error! Your inventory is empty. Please enter a part before you remove one!";
						
						print_StackMenu();
						std::cin >> SecondMenu;
					}
				}
				else if (SecondMenu == 3) // viewing all parts in the stack //
				{
					while (!stack.empty())
					{
						part = stack.top(); // TESTING.... COUDL BE BUG? // <---- ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION

						std::cout << "\nSerial Number: " << part.get_SerialNumber() << std::endl;
						std::cout << "Manufacture Date: " << part.get_ManufactureDate() << std::endl;
						std::cout << "Lot Number: " << part.get_LotNum() << std::endl;

						stack.pop();
					}
					print_StackMenu();
					std::cin >> SecondMenu;
				}
				else // exit //
				{
					break;
				}
			}
			break;
		}
		else
		{
			print_QueueMenu();
			std::cin >> SecondMenu;
			while (SecondMenu > 0 && SecondMenu < 4)
			{
				if (SecondMenu == 1) // adding a part to the queue
				{
					std::cout << "\nEnter the serial number of the part you would like to enter.\n> ";
					std::cin >> SerialNum;

					std::cout << "Enter the date the part was manufactured (XX/XX/20XX).\n> ";
					std::cin >> ManufactureDate;

					std::cout << "Enter the lot number where the part is stored.\n> ";
					std::cin >> LotNum;

					part = inventory(SerialNum, ManufactureDate, LotNum); // constructing information to 'inventory object' //
					queue.push(part);
					print_QueueMenu();
					std::cin >> SecondMenu;
				}
				else if (SecondMenu == 2) // removing the most recent 'part' from the queue
				{
					if (queue.size() > 0)
					{
						part = queue.front();
						std::cout << "Serial Number: " << part.get_SerialNumber() << std::endl;
						std::cout << "Manufacture Date: " << part.get_ManufactureDate() << std::endl;
						std::cout << "Lot Number: " << part.get_LotNum() << std::endl;

						queue.pop();

						std::cout << "\nPart has been removed..." << std::endl;

						print_QueueMenu();
						std::cin >> SecondMenu;
					}
					else // if no items are in the queue to remove //
					{
						std::cout << "Error! Your inventory is empty. Please enter a part before you remove one!";

						print_QueueMenu();
						std::cin >> SecondMenu;
					}
				}
				else if (SecondMenu == 3) // viewing all parts in the queue
				{
					while (!queue.empty())
					{
						part = queue.front(); // TESTING.... COUDL BE BUG? // <---- ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION ATTENTION

						std::cout << "\nSerial Number: " << part.get_SerialNumber() << std::endl;
						std::cout << "Manufacture Date: " << part.get_ManufactureDate() << std::endl;
						std::cout << "Lot Number: " << part.get_LotNum() << std::endl;

						queue.pop();
					}
					print_QueueMenu();
					std::cin >> SecondMenu;
				}
				else // exit //
				{
					break;
				}
			}
			break;
		}
	}
	std::cout << "Exiting..." << std::endl;

	return 0;
}