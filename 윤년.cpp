#include <iostream>

using namespace std;

int main() {
	int year;

	cin >> year;

	if (year % 4 == 0 && year % 100 != 0) {
		//O
		cout << 1;
	}
	else if (year % 400 == 0) {
		//O
		cout << 1;
	}
	else {
		//X
		cout << 0;
	}

	return 0;
}