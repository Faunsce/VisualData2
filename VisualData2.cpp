// VisualData2.cpp : Defines the entry point for the application.
//

#include "VisualData2.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

void printData(const std::vector<int>& data);

int main()
{
	const int SIZE_OF_DATA = 10;
	std::vector<int> data(SIZE_OF_DATA);
	for (int i = 0; i < SIZE_OF_DATA; i++)
	{
		data[i] = i;
	}

	std::cout << "Your data Madame~" << std::endl
		<< [data]() {std::string msg; for (auto& num : data) { msg += std::to_string(num) + " "; } return msg; }() << std::endl << std::endl;

	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	std::shuffle(data.begin(), data.end(), randomEngine);

	std::cout << "Your data Madame~" << std::endl
		<< [data]() {std::string msg; for (auto& num : data) { msg += std::to_string(num) + " "; } return msg; }() << std::endl << std::endl;
	
	bool clean = true;
	for (int i = SIZE_OF_DATA - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (data[j] > data[j + 1])
			{
				clean = false;
				std::swap(data[j], data[j + 1]);
			}
		}
		if (clean)
			break;
		clean = true;
	}

	


	return 0;
}

void printData(const std::vector<int>& data)
{
	std::string msg = "Your data Madame~ \n";
	for (auto& num : data) 
	{ 
		msg += std::to_string(num) + " "; 
	}
	msg += "\n\n";
	std::cout << msg;
};
