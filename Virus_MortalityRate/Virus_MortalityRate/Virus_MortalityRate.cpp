// Virus_MortalityRate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Virus.h"
double population1, death1;
void GetInput()
{
    std::cout << "Enter the number of cases affected by virus ";
    std::cin >> population1;
    std::cout << "Enter the number of death by the virus ";
    std::cin >> death1;
}
int main()
{
    int choice;
    step1:
    std::cout << "\nPlease select the type of virus for calculating Mortality Rate \n";
    std::cout << "1.CovidVirus \n2.HivVirus \n3.BirdFlue \n4.Exit\n";
    std::cin >> choice;
    try
    {
        if (choice == 1)
        {
            GetInput();
            CovidVirus obj;
            std::cout << "CovidMortality rate is " << obj.GetMortalityRate(population1, death1) << " %";
            goto step1;
        }
        else if (choice == 2)
        {
            GetInput();
            HivVirus obj;
            std::cout << "Hiv Virus Mortality rate is " << obj.GetMortalityRate(population1, death1) << " %";
            goto step1;
        }
        else if (choice == 3)
        {
            GetInput();
            BirdFlue obj;
            std::cout << "Hiv Virus Mortality rate is " << obj.GetMortalityRate(population1, death1) << " %";
            goto step1;
        }
        else if (choice == 4)
        {
            return 0;
            
        }
        else
        {
            std::cout << "Please enter a valid choice";
            goto step1;
        }
    }
    catch (const std::exception&)
    {
        std::cout << "Please enter a valid number other than zero for number of virus affected cases";
        goto step1;
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
