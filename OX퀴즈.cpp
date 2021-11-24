#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	string* quiz = new string[t];

	for (int i = 0; i < t; i++)
	{
		cin >> quiz[i];
	}

	for (int i = 0; i < t; i++)
	{
		int plus = 0;
		int score = 0;
		string curr = quiz[i];
		for (int k = 0; k < curr.size(); k++)
		{
			if (curr.at(k) == 'O')
				plus++;
			else
				plus = 0;

			score += plus;
		}

		cout << score << endl;
	}

	return 0;
}