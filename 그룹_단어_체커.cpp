#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	string* str = new string[n];

	
	int count = n;
	bool flag = false;
	char prev = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];

		string target = str[i];
		bool check[26] = { false, };
		prev = target[0];
		check[target[0] - 'a'] = true;
		for (int j = 1; j < target.size(); j++)
		{
			if (target[j] == prev) {
				//O
			}
			else {
				if (check[target[j] - 'a'] == true) {
					//X
					count--;
					break;
				}
				else {
					check[target[j] - 'a'] = true;
					prev = target[j];
				}
			}
		}
	}

	cout << count;

	return 0;
}