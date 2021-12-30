#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//8 <= n, m <= 50
vector<int> sqrCount;
int n, m;

char ChangeStart(char start) {
	if (start == 'B')
		return 'W';
	else
		return 'B';
}

int ScanInput(char** input, int left, int top) {
	char leftTop = input[left][top];
	int count1 = 0;

	char start;

	start = leftTop;
	for (int i = left; i < left + 8; i++)
	{
		for (int j = top; j < top + 8; j++)
		{
			if ((j-top) % 2 != 0) {
				if (start == input[i][j]) {
					count1++;
				}
			}
			else {
				if (start != input[i][j]) {
					count1++;
				}
			}
		}

		start = ChangeStart(start);
	}


	int count2 = 0;
	start = ChangeStart(leftTop);
	for (int i = left; i < left + 8; i++)
	{
		for (int j = top; j < top + 8; j++)
		{
			if ((j - top) % 2 != 0) {
				if (start == input[i][j]) {
					count2++;
				}
			}
			else {
				if (start != input[i][j]) {
					count2++;
				}
			}
		}

		start = ChangeStart(start);
	}

	return min(count1, count2);
}

int main() {
	cin >> n >> m;

	char** input = new char*[n];

	for (int i = 0; i < n; i++) {
		input[i] = new char[m];
		cin >> input[i];
	}

	
	for (int left = 0; left < n-7; left++)
	{
		for (int top = 0; top < m-7; top++)
		{
			sqrCount.push_back(ScanInput(input, left, top));
		}
	}

	cout << *min_element(sqrCount.begin(), sqrCount.end());
	

	return 0;
}