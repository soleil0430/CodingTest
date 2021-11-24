#include <iostream>
#include <string>

using namespace std;

void Swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void Reverse(string& str) {
	for (int i = 0; i < str.size()/2; i++)
	{
		Swap(str[i], str[str.size() - 1 - i]);
	}
}

int main() {
	string a, b;

	cin >> a >> b;
	
	Reverse(a);
	Reverse(b);
	
	cout << max(stoi(a), stoi(b));

	return 0;
}