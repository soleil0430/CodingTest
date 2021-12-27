#include <iostream>
#include <cmath>

using namespace std;

bool IsPrimeNumber(int n) {
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	int count = 0;

	cin >> n;

	int a = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (IsPrimeNumber(a))
			count++;
	}

	cout << count;


	return 0;
}