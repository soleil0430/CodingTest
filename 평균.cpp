#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	float* score = new float[n];

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}

	float max = score[0];
	for (int i = 0; i < n; i++)
	{
		if (max < score[i])
			max = score[i];
	}

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		score[i] = score[i] / max * 100.0f;
		sum += score[i];
	}

	cout << sum / n;
	

	return 0;
}