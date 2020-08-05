#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
int n;

int next_per() {
    int i = n-1;
    for(; i>0; i--) {
        if(arr[i] >= arr[i-1]) {
            break;
        }
    }
    if(i == 0) return -1;
    int j = n-1;
    for(; j>=i; j--) {
        if(arr[j] >= arr[i-1]) {
            break;
        }
    }
    swap(arr[i-1], arr[j]);
    sort(arr.begin() + i, arr.end());
    return 0;
}

int main() {
    int input;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++) {
        arr.push_back(i);
    }

    do {
        for(int i = 0; i<n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } while(next_per() != -1);

    return 0;
}