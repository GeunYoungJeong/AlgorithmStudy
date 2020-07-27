#include <iostream>

using namespace std;

int cnt[10000] = { 0, };

int add(int Num) {
    // if (Num < 0) return 0;
    if (Num <= 1) return 1;
    if(cnt[Num]) return cnt[Num];
    return cnt[Num] = add(Num-1) + add(Num-2) + add(Num-3);
}

int main(void) {
    int N;
    cin >> N;

    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = 4;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cout << add(num) << endl;
    }

    return 0;
}