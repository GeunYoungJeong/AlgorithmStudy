#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    int len = gems.size();
    vector <string> v = gems;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int n = v.size();
    vector <vector <int>> check(len, vector<int> (n, -1));
    int start, end;
    int length = 100001;
    for(int i = 0; i<len; i++) {
        bool state = false;
        for(int j = 0; j<n; j++) {
            if(i > 0) check[i][j] = check[i-1][j];
            if(gems[i] == v[j]) check[i][j] = i;
            if(check[i][j] == -1) state = true;
        }

        if(!state) {        
            int t_start = 100001, t_end = -1;
            for(int j = 0; j<n; j++) {
               if(check[i][j] < t_start) t_start = check[i][j];
                if(check[i][j] > t_end) t_end = check[i][j];
            }

            if(!state && (t_end-t_start+1) < length) {
                length = (t_end - t_start + 1);
                start = t_start;
                end = t_end;
            }
        }
    }
    vector<int> answer;
    answer.push_back(start+1);
    answer.push_back(end+1);
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    vector <string> a(n);
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    solution(a);
}