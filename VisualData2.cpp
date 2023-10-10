// VisualData2.cpp : Defines the entry point for the application.
//

#include "VisualData2.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <numeric>
#include <thread>
#include <chrono>

#define SCREEN_CLEAR "\x1b[2J\x1b[H"

namespace dataAlgorithms {
	void bubbleSort(std::vector<int>& data);
	void bogoSort(std::vector<int>& data);
	void insertionSort(std::vector<int>& data);
}

std::vector<int> generateDataSet();
void printData(const std::vector<int>& data);
void randomizeData(std::vector<int>& data);
void sortData(std::vector<int>& data);

int main()
{
	bool runAgain;
	std::vector<int> data;

	do {
		runAgain = false;

		data = generateDataSet();

		std::cout << SCREEN_CLEAR;
		printData(data);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		randomizeData(data);

		std::cout << SCREEN_CLEAR;
		printData(data);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << SCREEN_CLEAR;
		sortData(data);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::cout << SCREEN_CLEAR;
		printData(data);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} while (runAgain);

	return 0;
}

namespace dataAlgorithms {
	void bubbleSort(std::vector<int>& data)
	{
		bool clean = true;
		for (int i = data.size() - 1; i >= 0; i--)
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
			for (int i = 0; i < data.size() - 1; i++)
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
		for (int i = 0; i < data.size(); i++)
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
}

std::vector<int> generateDataSet()
{
	int dataSetSize;
	do {
		std::string userInput;
		std::cout << "Please set the size of the array [10 - 100] : ";
		std::cin >> userInput;

		int value = std::stoi(userInput);
		if (value > 100 || value < 10)
		{
			std::cout << "Invalid Input, please try again!" << std::endl;
			continue;
		}
		dataSetSize = value;
		break;
	} while (true);

	std::vector<int> data(dataSetSize);
	std::iota(data.begin(), data.end(), 0);

	return data;
};

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

void sortData(std::vector<int>& data)
{
	bool processAgain = false;
	do {
		processAgain = false;
		std::string userInput;
		
		std::cout << "Please select an option for sorting.\n"
			<< "[0] - BogoSort \n"
			<< "[1] - BubbleSort \n"
			<< "[2] - InsertionSort \n"
			<< "Selection : ";
		
		std::cin.clear();
		std::getline(std::cin, userInput);
		if (userInput.empty() || !std::isdigit(userInput[0]))
		{
			std::cout << "Invalid input try again." << std::endl;
			processAgain = true;
			continue;
		};

		switch (std::stoi(userInput.substr(0, 1)))
		{
		case 0:
			dataAlgorithms::bogoSort(data);
			break;
		case 1:
			dataAlgorithms::bubbleSort(data);
			break;
		case 2:
			dataAlgorithms::insertionSort(data);
			break;
		default:
			processAgain = true;
			break;
		}
	} while (processAgain);
};