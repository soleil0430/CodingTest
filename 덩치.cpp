#include <iostream>

using namespace std;

template<typename T, int v>
void Function(T a) {
	cout << a + v << endl;
}

int main() {
	Function<int, 5>(5);
	Function<float, 5>(5.5f);



	/*int n;
	cin >> n;
	int* arrX = new int[n];
	int* arrY = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arrX[i] >> arrY[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (arrX[i] < arrX[j] && arrY[i] < arrY[j])
				count++;
		}
		cout << count + 1 << " ";
	}*/



	return 0;
}