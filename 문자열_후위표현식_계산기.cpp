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
    /// it���� ���ڿ��� �о ���� Ȥ�� ������ �߽߰� �ʱ�ȭ�Ѵ�
    /// �Լ� ȣ�� �� it�� �� ���� ��ġ�� ������ ����Ű�� �����Ѵ�.
    /// ���ڿ��� ��� ������ it�� end�� �ȴ�.
    /// </summary>
    /// <param name="it">���� ���ڿ� �ݺ���</param>
    /// <param name="itEnd">���� ���ڿ� end</param>
    /// <returns>����, �����ڸ� ���������� �о��°�?</returns>
    bool ReadExpression(string::iterator& it, string::iterator itEnd) {
        string number;

        while (it != itEnd) {
            char c = *it;

            //����
            if (('0' <= c && c <= '9') || (c == '.')) {
                number.push_back(c);
                it++;
            }
            else {
                //���� �дٰ� ������ ����
                if (number.size() > 0) {
                    type = EToken::NUMBER;
                    data = stod(number);
                    return true;
                }

                //������
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

        //���ڿ��� ������ token�� ���ڴ�.
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
        //����
        if (token.type == EToken::NUMBER) {
            postfix.push_back(token);
        }
        //������
        else if (token.type == EToken::OPERATOR) {
            //')'�� ������ == '(' ���������� �� �̾Ƴ���
            if (token.data == ')') {
                while (!operStack.empty() && operStack.top().data != '(') {
                    postfix.push_back(operStack.top());
                    operStack.pop();
                }

                //'('�� ���� ǥ��Ŀ� ���� �ȵǴ� ����
                if (operStack.top().data == '(')
                    operStack.pop();
            }
            else {
                //������ ������ �����
                if (operStack.empty()) {
                    operStack.push(token);
                }
                //�������� �����ڰ� ���� ������ top���� �켱������ ����
                //Ȥ�� '(' �� ������ �Ѵ� (= ')'�� ���� �����̴�)
                else if (operStack.top().priority < token.priority || token.data == '(') {
                    operStack.push(token);
                }
                //��Ģ �����ڴ�
                else {
                    //������ top �켱������ �������� ������ �켱�������� ���������� �̾Ƴ���
                    while (!operStack.empty() && operStack.top().priority >= token.priority) {
                        postfix.push_back(operStack.top());
                        operStack.pop();
                    }
                    operStack.push(token);
                }
            }
        }
    }

    //�����ִ� ������ ���� �� �̾Ƴ���
    while (!operStack.empty()) {
        postfix.push_back(operStack.top());
        operStack.pop();
    }

    tokens = postfix;
}

double CalculatePostfix(vector<Token>& postfix) {
    stack<double> numStack;

    for (auto token : postfix) {
        //����
        if (token.type == EToken::NUMBER) {
            numStack.push(token.data);
        }
        //������
        else if (token.type == EToken::OPERATOR) {
            //���� ������ �� �� 2��
            double a = numStack.top();
            numStack.pop();
            double b = numStack.top();
            numStack.pop();

            //������ ���� a, b �ΰ� �����ϰ� ���� ���ÿ� push
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

    //��������� ���� ������ ������ �ϳ�
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
