#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int n = new_id.length();

    for(int i = 0; i<n; i++) {
        if(new_id[i] >= 'a' && new_id[i] <='z') {
            answer.push_back(new_id[i]);
        }
        else if(new_id[i] >= 'A' && new_id[i] <='Z') {
            answer.push_back(tolower(new_id[i]));
        }
        else if(new_id[i] >= '0' && new_id[i] <='9') {
            answer.push_back(new_id[i]);
        }
        else if(new_id[i] == '-' || new_id[i] == '_') {
            answer.push_back(new_id[i]);
        }
        else if(new_id[i] == '.') {
            if(i==0) answer.push_back(new_id[i]);
            else {
                if(answer[answer.length()-1] != '.') answer.push_back(new_id[i]);
            }
        }
    }

    if(answer[0] == '.') answer.erase(answer.begin());
    if(answer[answer.length()-1] == '.') answer.erase(answer.end()-1);

    if(answer.length() == 0) answer = "a";
    if(answer.length() >= 16) {
        answer = answer.substr(0, 15);
        if(answer[answer.length()-1] == '.') answer.erase(answer.end()-1);
    }
    while(answer.length() <= 2) {
        answer.push_back(answer[answer.length()-1]);
    }

    return answer;
}

int main() {
    string str;
    cin >> str;
    solution(str);
}