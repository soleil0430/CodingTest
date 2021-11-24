#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n;
	cin >> n;

	int startX = 0;
	int startY = 2;

	int nowX;
	int nowY;

	for (;;)
	{
		nowX = startX + 1;
		nowY = startY - 1;
		n--;
		if (n == 0) {
			cout << nowY << "/" << nowX;
			return 0;
		}

		nowX += 1;
		n--;
		if (n == 0) {
			cout << nowY << "/" << nowX;
			return 0;
		}

		while (nowX != 1) {
			nowX -= 1;
			nowY += 1;
			n--;
			if (n == 0) {
				cout << nowY << "/" << nowX;
				return 0;
			}
		}

		nowY += 1;
		n--;
		if (n == 0) {
			cout << nowY << "/" << nowX;
			return 0;
		}


		while (nowY != 2) {
			nowX += 1;
			nowY -= 1;
			n--;
			if (n == 0) {
				cout << nowY << "/" << nowX;
				return 0;
			}
		}

		startX = nowX;
		startY = nowY;
	}


	return 0;
}