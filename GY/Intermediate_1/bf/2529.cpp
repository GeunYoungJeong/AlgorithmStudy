#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    scanf("%d\n", &k);
    char input[10];
    
    cin.clear();
    for(int i = 0; i<k; i++) {
        scanf("%s", &input[i]);
    }

    vector <int> MAX;
    vector <int> MIN;

    for(int i = 0; i<=k; i++) {
        MIN.push_back(i);
        MAX.push_back(9-i);
    }

    do {
        bool check = false;
        for(int i = 0; i<k; i++) {
            if(input[i] == '<') {
                if(MIN[i] >= MIN[i+1]) {
                    check = true;
                    break;
                }
            }
            else {
                if(MIN[i] <= MIN[i+1]) {
                    check = true;
                    break;
                }
            }
        }
        if(!check) break;
    } while(next_permutation(MIN.begin(), MIN.end()));

    do {
        bool check = false;
        for(int i = 0; i<k; i++) {
            if(input[i] == '<') {
                if(MAX[i] >= MAX[i+1]) {
                    check = true;
                    break;
                }
            }
            else {
                if(MAX[i] <= MAX[i+1]) {
                    check = true;
                    break;
                }
            }
        }
        if(!check) break;
    } while(prev_permutation(MAX.begin(), MAX.end()));

    for(int i = 0; i<=k; i++) {
        printf("%d", MAX[i]);
    }
    printf("\n");

    for(int i = 0; i<=k; i++) {
        printf("%d", MIN[i]);
    }
    printf("\n");

    return 0;
}