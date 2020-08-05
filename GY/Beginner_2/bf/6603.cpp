#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> set;
int k, input;

int next_per() {
    int i = k-1;
    for(; i>0; i--) {
        if(set[i] > set[i-1]) {
            break;
        }
    }
    if(i == 0) return -1;
    int j = k-1;
    for(; j>=i; j--) {
        if(set[j] >= set[i-1]) {
            break;
        }
    }
    swap(set[i-1], set[j]);
    sort(set.begin() + i, set.end());
    return 0;
}

int main() {
    while(1) {
        scanf("%d", &k);
        if(k == 0) return 0;
        vector <int> arr;
        arr.clear();
        set.clear();
        for(int i = 0; i<k; i++) {
            scanf("%d", &input);
            arr.push_back(input);
        }
        for(int i = 0; i<6; i++) {
            set.push_back(1);
        }
        for(int i = 0; i<k-6; i++) {
            set.push_back(0);
        }

        do {
            // for(int i = 0; i<k; i++) {
            //     printf("%d ", set[i]);
            // }
            // printf("\n");
            for(int i = 0; i<k; i++) {
                if(set[i] == 1) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
        } while(prev_permutation(set.begin(), set.end()));
        printf("\n");
    }
}