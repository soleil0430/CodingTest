#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (auto command : commands) {
        //command[0] : ���� ����
        //command[1] : �� ����
        //command[2] : �κ� �迭�� ���� ����
        //zero-base ���� �ƴϱ� ������ �ε����� ��� �� (-1) �ʼ�

        auto begin = array.begin() + (command[0] - 1); //���� ����(iterator)
        auto end = array.begin() + (command[1] - 1);   //�� ����(iterator)

        
        copy(begin, end + 1, back_inserter(temp)); //[begin, end) �̱� ������ end+1
                                                   //temp�� ���� ����

        sort(temp.begin(), temp.end()); //������ ���� ����

        answer.push_back(temp[command[2] - 1]); //�� ����

        temp.clear();
    }

    return answer;
}

void main() {
    auto result = solution({ 1,5, 2, 6, 3, 7, 4 }, { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} });

    for (auto a : result)
        cout << a << " ";
}