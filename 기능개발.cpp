/*
* 문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
*
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    bool prevSuccess = true;
    int count = 0;
    int sum = 0;

    while (sum < progresses.size()) {
        count = 0;
        prevSuccess = true;

        //Develop
        for (int i = 0; i < progresses.size(); ++i) {
            if (0 < progresses[i] && progresses[i] < 100)
                progresses[i] = progresses[i] + speeds[i];
        }

        //Check
        for (int i = 0; i < progresses.size(); ++i) {
            if (progresses[i] >= 100 && prevSuccess) {
                count++;
                progresses[i] = -1;
            }
            prevSuccess = (progresses[i] == -1);
        }

        if (count > 0) {
            sum += count;
            answer.push_back(count);
        }
    }

    return answer;
}

int main() {
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    vector<int> answer = solution(progresses, speeds);

    for (auto a : answer)
        cout << a << " ";


    return 1;
}