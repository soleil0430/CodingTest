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

    //두 문자열 벡터를 사전편찬 순으로 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (i = 0; i < completion.size(); ++i) {
        //매칭 안되는 부분 발견
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    }

    //반복문이 끝나면 비교하지 못한(할 수없는) participant[마지막]이 남게된다.
    //이는 completion에 같은 값이 없다는 뜻이므로 이를 반환하면 된다.
    answer = participant[i];
    return answer;
}

void main() {
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
    cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
    cout << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
}