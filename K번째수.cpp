#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (auto command : commands) {
        //command[0] : 시작 지점
        //command[1] : 끝 지점
        //command[2] : 부분 배열의 선택 지점
        //zero-base 값이 아니기 때문에 인덱스로 사용 시 (-1) 필수

        auto begin = array.begin() + (command[0] - 1); //시작 구간(iterator)
        auto end = array.begin() + (command[1] - 1);   //끝 구간(iterator)

        
        copy(begin, end + 1, back_inserter(temp)); //[begin, end) 이기 때문에 end+1
                                                   //temp에 구간 복사

        sort(temp.begin(), temp.end()); //복사한 구간 정렬

        answer.push_back(temp[command[2] - 1]); //답 기입

        temp.clear();
    }

    return answer;
}

void main() {
    auto result = solution({ 1,5, 2, 6, 3, 7, 4 }, { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} });

    for (auto a : result)
        cout << a << " ";
}