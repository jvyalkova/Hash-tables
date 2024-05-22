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

	return 0;
}