#include <bits/stdc++.h>

using namespace std;

int n, m;

int calculate(vector <int> &first, vector <int> &second, int num, bool state) {
    int mid;
    int ans = 0;
    int left = 0;
    int right = n-1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(first[mid] == num) {
            if(!state) {
                left = mid + 1;
                ans = mid + 1;
            }   
            else {
                right = mid - 1;
                ans = mid;
            }
        }
        else if(first[mid] < num) {
            left = mid+1;
        } 
        else {
            right = mid-1;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    vector <int> first(n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &first[i]);
    }

    scanf("%d", &m);
    vector <int> second(m);
    for(int i = 0; i<m; i++) {
        scanf("%d", &second[i]);
    }
    
    sort(first.begin(), first.end());

    for (int i = 0; i<m; i++) {
        printf("%d ", calculate(first, second, second[i], false) - calculate(first, second, second[i], true));
    }
    return 0;
}