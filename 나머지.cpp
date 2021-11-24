#include <iostream>

using namespace std;

int main() {
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	int count[42] = { 0, };

	for (int i = 0; i < 10; i++)
	{
		count[arr[i] % 42]++;
	}

	int answer = 0;
	for (int i = 0; i < 42; i++)
	{
		if (count[i] != 0)
			answer++;
	}

	cout << answer;

	return 0;
}
