#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	string str = to_string(a * b * c).c_str();
	int size = str.size();
	const char* cstr = str.c_str();

	int count[10] = {0, };

	for (int i = 0; i < size; i++) {
		count[cstr[i] - 48]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}