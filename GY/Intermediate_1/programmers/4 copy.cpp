#include <bits/stdc++.h>

using namespace std;

int row, col;
int total = 0;
vector <int> cnt;

void calculate(int l, int count, int case) {
    if(count > total) return;

    if(l == row) {
        if(count == total) {

        }
    }


}

int solution(vector<vector<int>> a) {
    unsigned long long answer = 0;
    col = a[0].size();
    row = a.size();

    for(int i = 0; i<col; i++) {
        int t = 0;
        for(int j = 0; j<row; j++) {
            t += a[j][i];
            total += a[j][i];
        }
        cnt.push_back(t);
    }
    
    return answer;
}

int main() {
    int c, r;
    cin >> c >> r;
    vector <vector<int>> input(c, vector<int> (r));
    for(int i =0 ; i<c; i++) {
        for(int j = 0; j<r; j++) {
            cin >> input[i][j];
        }
    }
    cout << solution(input);

}