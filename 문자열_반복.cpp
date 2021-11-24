#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;

	int repeat;
	string str;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> repeat >> str;

		for (int j = 0; j < str.size(); j++)
		{
			for (int k = 0; k < repeat; k++)
			{
				cout << str[j];
			}
		}

		cout << endl;
	}
	




	return 0;
}