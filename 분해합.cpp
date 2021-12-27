#include <iostream>

using namespace std;

int DivideSum(int n) {
	int result = 0;
	while (n != 0) {
		result += n % 10;
		n /= 10;
	}

	return result;
}

int Func2(int n) {
	return n + DivideSum(n);
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		if (Func2(i) == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;

	return 0;
}