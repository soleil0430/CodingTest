#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x;
	cin >> y;

	if (x > 0) {
		//1 4
		if (y > 0) {
			//1
			cout << 1;
		}
		else {
			//4
			cout << 4;
		}
	}
	else {
		// 2 3
		if (y > 0) {
			//2
			cout << 2;
		}
		else {
			//3
			cout << 3;
		}
	}


	return 0;
}