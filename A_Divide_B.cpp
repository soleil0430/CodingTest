/*
* https://www.acmicpc.net/problem/1008
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	std::cout.precision(9);
	cout << std::fixed << (double)a / b;
	
	return 0;
}