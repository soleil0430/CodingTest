#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	int count[26];
	for (int i = 0; i < 26; i++){
		count[i] = -1;
	}
	

	for (int i = 0; i < str.size(); i++)
	{
		if (count[str[i]-'a'] == -1)
			count[str[i]-'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << count[i] << " ";
	}


	return 0;
}