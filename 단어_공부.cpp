#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	int count[26] = { 0, };

	for (int i = 0; i < str.size(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 'a' - 'A';

		count[str[i] - 'a']++;
	}

	int index = 0;
	int max = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < count[i]) {
			max = count[i];
			index = i;
		}
	}

	int c = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max == count[i])
			c++;
	}
	
	if (c > 1)
		cout << "?";
	else
		cout << (char)('A' + index);

	return 0;
}