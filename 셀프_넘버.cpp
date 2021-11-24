#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetNumber(int number) {
	vector<int> result;

	for (int i = 1; i <= 5; i++)
	{
		int a = pow(10, i);
		int b = pow(10, i-1);
		int insert = (number % a) - (number % b);

		result.push_back(insert / b);
	}

	return result;
}

int Kaprekar(int number) {
	int sum = 0;
	for (auto item : GetNumber(number)) {
		sum += item;
	}
	return number + sum;
}


int main() {
	vector<int> a;
	for (int i = 1; i <= 10000; ++i) {
		a.push_back(Kaprekar(i));
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	int index = 0;

	for (int i = 1; i <= 10000; i++)
	{
		if (i != a[index]) {
			cout << i << endl;
		}
		else {
			index++;
		}
	}

	
	return 0;
}