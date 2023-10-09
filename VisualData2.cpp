// VisualData2.cpp : Defines the entry point for the application.
//

#include "VisualData2.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <numeric>

const int SIZE_OF_DATA = 20;

void printData(const std::vector<int>& data);
void randomizeData(std::vector<int>& data);
void bubbleSort(std::vector<int>& data);
void bogoSort(std::vector<int>& data);
void insertionSort(std::vector<int>& data);

int main()
{
	std::vector<int> data(SIZE_OF_DATA);
	std::iota(data.begin(), data.end(), 0);

	printData(data);

	insertionSort(data);

	randomizeData(data);

	printData(data);
	
	bubbleSort(data);

	printData(data);

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

	return;
};

void randomizeData(std::vector<int>& data)
{
	std::random_device randomDevice;
	std::mt19937 randomEngine(randomDevice());
	std::shuffle(data.begin(), data.end(), randomEngine);

	return;
}

void bubbleSort(std::vector<int>& data)
{
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

	return;
}

void bogoSort(std::vector<int>& data)
{
	bool clean = true;
	do
	{
		clean = true;
		for (int i = 0; i < SIZE_OF_DATA - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				randomizeData(data);
				clean = false;
				break;
			}
		}
	} while (!clean);

	return;
}

void insertionSort(std::vector<int>& data)
{
	for (int i = 0; i < SIZE_OF_DATA; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (data[j] < data[j - 1])
			{
				std::swap(data[j], data[j - 1]);
			}
		}
	}

	return;
}