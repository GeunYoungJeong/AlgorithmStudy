#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> num;
    vector <char> oper;
    int input;
    char c;
    cin >> input;
    int result = input;
    bool check = true;
    while(1) {
        scanf("%c", &c);
        if(c == '-') {
            check = false;
        }
        if(c == '\n') {
            break;
        }
        cin >> input;
        if(!check) {
            result -= input;
        }
        else result += input;
    }
    printf("%d\n", result);
    return 0;
}