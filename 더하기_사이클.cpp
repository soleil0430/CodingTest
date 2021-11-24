#include <iostream>

using namespace std;

int main() {
	int n;
	int prev, curr;
	int cycle = 0;

	cin >> n;
	
	prev = curr = n;

	do {
		cycle++;

		curr = (prev / 10) + (prev % 10);

		prev = ((prev % 10) * 10) + curr % 10;
	} while (prev != n);

	cout << cycle;

	return 0;
}