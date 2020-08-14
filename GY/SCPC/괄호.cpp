#include <bits/stdc++.h>

using namespace std;

int answer;

void calculate(string str) {
    stack<char> s;
    int len = str.length();
    int result = 0;
    int open = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
            open++;
        }
        else
        {
            if (!s.empty())
            {
                if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{'))
                {
                    result += 2;
                    open = 0;
                    s.pop();
                }
                else
                {
                    if (answer <= result) answer = result;
                    result = 0;
                    while (!s.empty())
                        s.pop();
                }
            } else {
                if (answer <= result) answer = result;
                result = 0;
            }
        }
    }
    if(!s.empty()) {
        if( (str[len-1-result] == '(' && str[len-1] == ')') || (str[len-1-result] == '[' && str[len-1] == ']') || (str[len-1-result] == '{' && str[len-1] == '}')) {

            if (answer <= result) answer = result;
        } else {
            result = 2;
            
            if (answer <= result) answer = result;
        }
    } else {
        if (answer <= result) answer = result;
    }
}
 
int main()
{
    int t;
    string input;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        answer = 0;
        cin >> input;
        calculate(input);
        printf("Case #%d\n%d\n", k, answer);
    }
}