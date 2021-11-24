#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int sum = 0;

	cin >> n;
	char* str = new char[n];
	cin >> str;

	for (int i = 0; i < n; i++)
	{
		sum += static_cast<int>(str[i]) - static_cast<int>('0');
	}

	cout << sum;

	return 0;
}