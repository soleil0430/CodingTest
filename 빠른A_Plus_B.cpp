#include <iostream>

using namespace std;

int main() {
	int t;
	int a, b;
	cin >> t;

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}