#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
int n;

bool comp(int a, int b) {
    return a >= b;
}

int prev_per() {
    int i = n-1;
    for(; i>0; i--) {
        if(arr[i] < arr[i-1]) {
            break;
        }
    }
    if(i == 0) return -1;
    int j = n-1;
    for(; j>=i; j--) {
        if(arr[j] < arr[i-1]) {
            break;
        }
    }
    swap(arr[i-1], arr[j]);
    sort(arr.begin() + i, arr.end(), comp);
    return 0;
}

int main() {
    int input;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        scanf("%d", &input);
        arr.push_back(input);
    }

    if(prev_per() == -1) {
        printf("-1\n");
    } else {
        for(int i = 0; i<n; i++) {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}