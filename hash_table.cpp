#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
	int numContainers;
	string input;
	int option;

	cout << "Select an option: " << endl;
	cout << "1. Hash table with collisions" << endl;
	cout << "2. Hash table without collisions" << endl;
	cin >> option;

	ifstream inputFile("input.txt");

	if (!inputFile.is_open())
	{
		cout << "Unable to open file" << endl;
		return 1;
	}

	inputFile >> numContainers;
	inputFile.ignore();

	getline(inputFile, input);

	inputFile.close();

	istringstream iss(input);
	string word;
	vector<string> words;

	while (iss >> word)
	{
		words.push_back(word);
	}


	if (option == 1) // Hash table with collisions
	{
		unordered_map<int, vector < string>> containers;

		for (string word : words)
		{
			int sum = 0;
			for (char c : word)
			{
				sum += int(c);
			}

			int containerNum = sum % numContainers;

			containers[containerNum].push_back(word);
		}

		for (int i = 0; i < numContainers; i++)
		{
			cout << "Container " << i << ": ";
			if (containers[i].empty())
				cout << "null";
			else
			{
				for (string word : containers[i])
					cout << word << " ";
			}
			cout << endl;
		}
	}
	else if (option == 2) // Hash table without collisions using linear probing
	{
		unordered_map<int, string> containers;

		for (string word : words)
		{
			int sum = 0;
			for (char c : word)
			{
				sum += int(c);
			}

			int containerNum = sum % numContainers;
			int originalContainerNum = containerNum;

			while (containers.find(containerNum) != containers.end())
			{
				containerNum = (containerNum + 1) % numContainers;
				if (containerNum == originalContainerNum)
				{
					numContainers++;
				}
			}

			containers[containerNum] = word;
		}

		for (int i = 0; i < numContainers; i++)
		{
			cout << "Container " << i << ": ";
			if (containers.find(i) == containers.end())
				cout << "null";
			else
				cout << containers[i];
			cout << endl;
		}
	}
	else
	{
		cout << "Invalid option selected." << endl;
	}

	return 0;
}
