#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int count = 0;

	getline(cin, str);

	if (str[str.size()-1] != ' ')
		str.append(" ");

	bool flag = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
			flag = true;

		if (flag) {
			if (str[i] == ' ')
				count++;
		}
	}

	cout << count;

	return 0;
}