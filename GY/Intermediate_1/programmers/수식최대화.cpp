#include <bits/stdc++.h>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    deque <long long> num_origin;
    deque <char> operand_origin;
    int s = expression.size();
    string str = "";
    for(int i = 0; i<s; i++) {
        if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            operand_origin.push_back(expression[i]);
            num_origin.push_back(stoi(str));
            str = "";
        }
        else {
            str += expression[i];
        }
    }
    num_origin.push_back(stoi(str));
    operand_origin.push_back('X');

    char priority[3] = {'*','+', '-'};
    do {
        deque <long long> num = num_origin;
        deque <char> operand = operand_origin;
        for(int i = 0; i<3; i++) {
            while(operand.front() != 'X') {
                if(operand.front() == priority[i]) {
                    long long temp = num.front();
                    num.pop_front();
                    if(operand.front() == '*') temp *= num.front();
                    else if(operand.front() == '+') temp += num.front();
                    else temp -= num.front();
                    num.pop_front();
                    num.push_front(temp);
                    operand.pop_front();
                }
                else {
                    num.push_back(num.front());
                    operand.push_back(operand.front());
                    num.pop_front();
                    operand.pop_front();
                }
            }
            num.push_back(num.front());
            operand.push_back(operand.front());
            num.pop_front();
            operand.pop_front();
        }
        if(abs(num.front()) > answer) answer = abs(num.front());
    } while(next_permutation(priority, priority+3));
    return answer;
}

int main() {
    string str;
    cin >> str;
    cout << solution(str);
}