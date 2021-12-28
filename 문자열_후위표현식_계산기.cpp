// String Calculator
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

enum class EToken : int {
    OPERATOR = 0,
    NUMBER = 1,
};

struct Token {
    EToken type;
    unsigned char priority;
    double data;

    /// <summary>
    /// it부터 문자열을 읽어서 숫자 혹은 연산자 발견시 초기화한다
    /// 함수 호출 후 it는 다 읽은 위치의 다음을 가리키게 변경한다.
    /// 문자열을 모두 읽으면 it는 end가 된다.
    /// </summary>
    /// <param name="it">읽을 문자열 반복자</param>
    /// <param name="itEnd">읽을 문자열 end</param>
    /// <returns>숫자, 연산자를 성공적으로 읽었는가?</returns>
    bool ReadExpression(string::iterator& it, string::iterator itEnd) {
        string number;

        while (it != itEnd) {
            char c = *it;

            //숫자
            if (('0' <= c && c <= '9') || (c == '.')) {
                number.push_back(c);
                it++;
            }
            else {
                //숫자 읽다가 연산자 나옴
                if (number.size() > 0) {
                    type = EToken::NUMBER;
                    data = stod(number);
                    return true;
                }

                //연산자
                if (c == '*' || c == '/') {
                    priority = 2;
                }
                else if (c == '+' || c == '-') {
                    priority = 1;
                }
                else if (c == '(' || c == ')') {
                    priority = 0;
                }

                type = EToken::OPERATOR;
                data = c;
                it++;
                return true;
            }
        }

        //문자열의 마지막 token이 숫자다.
        if (number.size() > 0) {
            type = EToken::NUMBER;
            data = stod(number);
            return true;
        }

        return false;
    }

    void Show() {
        if (type == EToken::NUMBER)
            cout << (double)data << " ";
        else
            cout << (char)data << " ";
    }
};

void Tokenization(string expr, vector<Token>& postfix) {
    string::iterator it = expr.begin();

    for (; it != expr.end(); ) {
        Token token;
        token.ReadExpression(it, expr.end());
        postfix.push_back(token);
    }
}

void ToPostfix(vector<Token>& tokens) {
    stack<Token> operStack;
    vector<Token> postfix;

    for (auto token : tokens) {
        //숫자
        if (token.type == EToken::NUMBER) {
            postfix.push_back(token);
        }
        //연산자
        else if (token.type == EToken::OPERATOR) {
            //')'를 만났다 == '(' 만날때까지 다 뽑아낸다
            if (token.data == ')') {
                while (!operStack.empty() && operStack.top().data != '(') {
                    postfix.push_back(operStack.top());
                    operStack.pop();
                }

                //'('는 후위 표기식에 포함 안되니 뺀다
                if (operStack.top().data == '(')
                    operStack.pop();
            }
            else {
                //연산자 스택이 비었다
                if (operStack.empty()) {
                    operStack.push(token);
                }
                //넣으려는 연산자가 스택 연산자 top보다 우선순위가 높다
                //혹은 '(' 을 넣으려 한다 (= ')'이 들어올 예정이다)
                else if (operStack.top().priority < token.priority || token.data == '(') {
                    operStack.push(token);
                }
                //사칙 연산자다
                else {
                    //스택의 top 우선순위가 넣으려는 연산자 우선순위보다 작을때까지 뽑아낸다
                    while (!operStack.empty() && operStack.top().priority >= token.priority) {
                        postfix.push_back(operStack.top());
                        operStack.pop();
                    }
                    operStack.push(token);
                }
            }
        }
    }

    //남아있는 연산자 스택 다 뽑아내기
    while (!operStack.empty()) {
        postfix.push_back(operStack.top());
        operStack.pop();
    }

    tokens = postfix;
}

double CalculatePostfix(vector<Token>& postfix) {
    stack<double> numStack;

    for (auto token : postfix) {
        //숫자
        if (token.type == EToken::NUMBER) {
            numStack.push(token.data);
        }
        //연산자
        else if (token.type == EToken::OPERATOR) {
            //숫자 스택의 맨 위 2개
            double a = numStack.top();
            numStack.pop();
            double b = numStack.top();
            numStack.pop();

            //연산자 따라 a, b 두개 연산하고 숫자 스택에 push
            switch ((char)token.data)
            {
            case '*':
                numStack.push(b * a);
                break;
            case '/':
                numStack.push(b / a);
                break;
            case '+':
                numStack.push(b + a);
                break;
            case '-':
                numStack.push(b - a);
                break;
            default:
                break;
            }
        }
    }

    //최종결과는 숫자 스택의 마지막 하나
    return numStack.top();
}

int main() {
    vector<Token> tokens;
    string infix = "1.1+2.2*3.3*((4.4-5.5)*6.6)";
    //cin >> infix;

    //===========================================
    cout << "Tokenization -------" << endl;
    Tokenization(infix, tokens);
    for (auto item : tokens)
        item.Show();

    cout << endl << "--------------------" << endl;
    //===========================================


    //===========================================
    cout << "ToPostfix ----------" << endl;
    ToPostfix(tokens);
    for (auto item : tokens)
        item.Show();

    cout << endl << "--------------------" << endl;
    //===========================================


    //===========================================
    cout << CalculatePostfix(tokens) << endl;
    //===========================================

    return 0;
}
