#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int studentCount;
		cin >> studentCount;

		float avg = 0;

		int* score = new int[studentCount];
		for (int j = 0; j < studentCount; j++)
		{
			cin >> score[j];
			avg += score[j];
		}

		avg /= studentCount;

		int count = 0;
		for (int j = 0; j < studentCount; j++)
		{
			if (score[j] > avg)
				count++;
		}


		float result = (float)count / (float)studentCount * 100.0f;

		cout.precision(3);
		cout << fixed << round(result * 1000) / 1000.0f << "%" << endl;
	}

	return 0;
}