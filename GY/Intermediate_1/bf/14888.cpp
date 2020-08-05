#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pl_count, mi_count, mu_count, di_count, MIN, MAX;
    vector <int> arr;
    MIN = 1000000000;
    MAX = -1000000000;
    int input[12];
    scanf("%d", &n);

    for(int i = 0; i<n; i++) {
        scanf("%d", &input[i]);
    }

    scanf("%d %d %d %d", &pl_count, &mi_count, &mu_count, &di_count);
    
    for(int i = 0; i<pl_count; i++) {
        arr.push_back(1);
    }
    for(int i = 0; i<mi_count; i++) {
        arr.push_back(2);
    }
    for(int i = 0; i<mu_count; i++) {
        arr.push_back(3);
    }
    for(int i = 0; i<di_count; i++) {
        arr.push_back(4);
    }

    do {
        int temp = input[0];
        for(int i = 0; i<n-1; i++) {
            if(arr[i] == 1) {
                temp += input[i+1];
            }
            if(arr[i] == 2) {
                temp -= input[i+1];
            }
            if(arr[i] == 3) {
                temp *= input[i+1];
            }
            if(arr[i] == 4) {
                temp /= input[i+1];
            }
        }
        if(temp > MAX) MAX = temp;
        if(temp < MIN) MIN = temp;
    } while(next_permutation(arr.begin(), arr.end()));

    printf("%d\n%d", MAX, MIN);
    return 0;
}