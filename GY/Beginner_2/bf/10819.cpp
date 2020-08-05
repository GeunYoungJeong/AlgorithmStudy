#include <bits/stdc++.h>

using namespace std;

vector <int> arr;
int n, m, sum;

int next_per() {
    int i = n-1;
    for(; i>0; i--) {
        if(arr[i] > arr[i-1]) {
            break;
        }
    }
    if(i == 0) return -1;
    int j = n-1;
    for(; j>=i; j--) {
        if(arr[j] > arr[i-1]) {
            break;
        }
    }
    // printf("%d %d", i, j);
    swap(arr[i-1], arr[j]);
    sort(arr.begin() + i, arr.end());
    return 0;
}

void calculate() {
    int temp = 0;
    for(int i = 0; i<n-1; i++) {
        temp += abs(arr[i] - arr[i+1]);
    }
    if(temp > m) m = temp;
}

int main() {
    int input;
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        scanf("%d", &input);
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    do {
        calculate();
    } while(next_per() != -1);
    
    printf("%d\n", m);

    return 0;
}