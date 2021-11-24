#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, v;

	cin >> a >> b >> v;


	int result1 = ceil((double)(v) / (a - b));
	int result2 = ceil((double)(v-b) / (a - b));

	cout << min(result1, result2);

	return 0;
}