#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;

	int h, w, n; //Ãþ, È£¼ö, ¼Õ´Ô

	int hN = 1;
	int wN = 1;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;
		

		hN = (n % h == 0) ? (h) : (n % h);
		wN = ceil((float)n / h);
		printf("%d", hN);
		printf("%02d\n", wN);
	}

	return 0;
}