#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector <char> l;
    int n = orders.size();

    for(int i = 0; i<n; i++) {
        int len = orders[i].size();
        for(int j = 0; j<len; j++) {
            if(count(l.begin(), l.end(), orders[i][j]) == 0) l.push_back(orders[i][j]);
        }
    }

    n = course.size();
    sort(l.begin(), l.end());
    do {
        for(int i = 0; i<n; i++) {
            int len = course[i];
            
        }
    }
    while(next_permutation(l.begin(), l.end()));

    sort(answer.begin(), answer.end());
    return answer;
}