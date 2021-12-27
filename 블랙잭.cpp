#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int max = 0;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				now = arr[i] + arr[j] + arr[k];
				if (max < now && now <= m)
					max = now;
			}
		}
	}

	cout << max;

	return 0;
}