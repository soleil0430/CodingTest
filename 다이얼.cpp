#include <iostream>
#include <string>
#include <vector>

using namespace std;

//[a ,b]
auto num1 = make_pair('A', 'C');
auto num2 = make_pair('D', 'F');

vector<pair<int, int>> numpad = {
	make_pair('A', 'C'), //2
	make_pair('D', 'F'), //3
	make_pair('G', 'I'), //4
	make_pair('J', 'L'), //5
	make_pair('M', 'O'), //6
	make_pair('P', 'S'), //7
	make_pair('T', 'V'), //8
	make_pair('W', 'Z'), //9
};

int main() {
	string str;
	int sum = 0;

	cout << (int)'0';
	cout << (int)'9';

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];

		for (int j = 0; j < numpad.size(); j++)
		{
			if (numpad[j].first <= c && c <= numpad[j].second) {
				str[i] = '1' + j + 1;

				sum += j + 1 + 2;
				break;
			}
		}
	}
	
	cout << sum;


	return 0;
}