#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> chro2 = {
	"c=", "c-", "d-", "lj", "nj", "s=", "z=",
};

int main() {
	string str;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		string sub = str.substr(i, 2);

		if (str.substr(i, 3).compare("dz=") == 0) {
			i += 2;
		}
		else {
			for (string comp : chro2) {
				if (sub.compare(comp) == 0) {
					i += 1;
					break;
				}
			}
		}

		count++;
	}

	cout << count;

	return 0;
}