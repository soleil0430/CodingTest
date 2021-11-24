#include <iostream>
#include <deque>

using namespace std;

deque<int> GetNumber(int number) {
	deque<int> result;

	while (1) {
		if (number == 0) break;
		result.push_front(number % 10);
		
		number = number / 10;
	}

	return result;
}

bool Check(deque<int> number) {
	if (number.size() < 3)
		return true;

	int a = (number[number.size() - 1] - number[0]);
	int b = (number.size() - 1);
	int n = a / b;

	for (int i = 1; i < number.size(); i++) {
		if (number[i] - number[i - 1] != n)
			return false;
	}

	return true;
}

int main() {
	int n = 1;
	int count = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		deque<int> number = GetNumber(i);

		if (Check(number)) {
			count++;
		}
	}

	cout << count;

	return 0;
}