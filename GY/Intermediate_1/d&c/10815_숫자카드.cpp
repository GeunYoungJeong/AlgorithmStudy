#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

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
        bool check = false;    
        int left = 0;
        int right = n-1;
        int mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if(first[mid] == second[i]) {
                check = true;
                printf("1 ");
                break;
            }
            if(first[mid] < second[i]) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if(!check) printf("0 ");        
    }
    return 0;
}