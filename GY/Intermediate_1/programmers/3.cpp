#include <bits/stdc++.h>

using namespace std;

int min_f[1000001];
int min_b[1000001];
int smin_f[1000001];
int smin_b[1000001];

int solution(vector<int> a) {

    int answer = 0;
    int n = a.size();

    if(n <= 2) {
        return n;
    }

    min_f[0] = a[0];
    min_b[n-1] = a[n-1];

    if(a[0] < a[1]) smin_f[0] = a[1];
    else smin_f[0] = a[0];

    if(a[n-1] < a[n-2]) smin_b[n-1] = a[n-2];
    else smin_b[n-1] = a[n-1];   

    for(int i = 1; i<n; i++) {
        if(a[i] < min_f[i-1]) {
            smin_f[i] = min_f[i-1];
            min_f[i] = a[i];
        }
        else {
            if(a[i] <= smin_f[i-1]) {
                smin_f[i] = a[i];
            }
            else {
                smin_f[i] = smin_f[i-1];
            }
            min_f[i] = min_f[i-1];
        }
    }

    for(int i = n-2; i>=0; i--) {
        if(a[i] < min_b[i+1]) {
            smin_b[i] = min_b[i+1];
            min_b[i] = a[i];
        }
        else {
            if(a[i] <= smin_b[i+1]) {
                smin_b[i] = a[i];
            }
            else {
                smin_b[i] = smin_b[i+1];
            }
            min_b[i] = min_b[i+1];
        }
    }

    for(int i = 0; i<n; i++) {
        cout << min_f[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i<n; i++) {
        cout << smin_f[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i<n; i++) {
        cout << min_b[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i<n; i++) {
        cout << smin_b[i] << "\t";
    }
    cout << endl;


    for(int i = 0; i<n; i++) {
        if(i==0 || i == n-1) {
            answer++;
        }
        else {
            if(min_f[i-1] >= a[i] || min_b[i+1] >= a[i]) {
                answer++;
                continue;
            }
            else {
                if(i >= 2 && i <= n-3) {
                    if((smin_f[i-1] > a[i] && a[i] < min_b[i+1]) || (min_f[i-1] > a[i] && a[i] < smin_b[i+1])) {
                        answer++;
                        continue;
                    }

                }
            }
        }
    }
    
    cout << answer << endl;
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector <int> input(n);
    for(int i = 0; i<n; i++) {
        cin >> input[i];
    }
    solution(input);
}