/*
* https://programmers.co.kr/learn/courses/30/lessons/42576
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i = 0;

    //�� ���ڿ� ���͸� �������� ������ ����
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (i = 0; i < completion.size(); ++i) {
        //��Ī �ȵǴ� �κ� �߰�
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    }

    //�ݺ����� ������ ������ ����(�� ������) participant[������]�� ���Եȴ�.
    //�̴� completion�� ���� ���� ���ٴ� ���̹Ƿ� �̸� ��ȯ�ϸ� �ȴ�.
    answer = participant[i];
    return answer;
}

void main() {
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
    cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
    cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
}