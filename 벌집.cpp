#include <iostream>

using namespace std;

int main() {
	int n;
	int count = 1;

	cin >> n;

	int interval = 0;
	int start = 1;
	int max = 2;

	while (true) {
		if (start <= n && n < max) {
			break;
		}

		interval += 6;
		start = max;
		max = start + interval;

		count++;
	}

	cout << count;

	return 0;
}