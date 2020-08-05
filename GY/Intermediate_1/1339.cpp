#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int MAX = 0;
    scanf("%d", &n);
    vector <string> input(n);

    for(int i = 0; i<n; i++) {
        scanf("%s", &input[i]);
    }
    for(int i = 0; i<n; i++) {
        printf("%s %d\n", input[i], input[i].size());
    }

    int num[10] = {0,1,2,3,4,5,6,7,8,9};

    // do {
    //     int temp;

    //     if(temp > MAX) MAX = temp;

    // }while();

    return 0;
}