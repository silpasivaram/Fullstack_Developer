//Engine_Efficiency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Engine.h"
#include <iostream>
using namespace std;
float input, output;
void getInput()
{
	std::cout << "Enter the Input Power ";
	std::cin >> input;
	std::cout << "Enter the Output Power ";
	std::cin >> output;
}
int main()
{
	int no;
	step:
	std::cout << "\n\tMenu";
	std::cout << "\n1.Internal Combustion Engine\n2.External Combustion Engine\n3.Exit\n";
	std::cout << "Enter your Choice ";
	cin >> no;
	try
	{

		if (no == 1)
		{
		step1:
			std::cout << "3.Petrol engine \n4.Desiel engine";
			std::cout << "\nEnter your Choice ";
			std::cin >> no;
			if (no == 3)
			{
				getInput();
				PetrolEngine obj;
				std::cout << "Efficiency of Pertrol Engine is " << obj.GetEfficiency(input, output);
				goto step;
			}
			else if (no == 4)
			{
				getInput();
				DieselEngine obj;
				std::cout << "Efficiency of Diesel Engine is " << obj.GetEfficiency(input, output);
				goto step;
			}
			else
			{
				std::cout << "Wrong Choice";
				goto step1;
			}
		}
		else if (no == 2)
		{
			getInput();
			SteamEngine obj;
			std::cout << "Efficiency of Steam engine is  " << obj.GetEfficiency(input, output);
			goto step;
		}
		else if (no == 3)
		{
			return 0;
		}
			
	else
	{
		std::cout << "Wrong Choice";
		goto step;
	}
	
	}
	catch (const std::exception&)
	{
		std::cout << "Please enter a valid number other than zero for input";
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
