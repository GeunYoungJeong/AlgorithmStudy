#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    srand((unsigned int)time(0));
    scanf("%d", &n);
    printf("문제 번호 : %d", rand()%n + 1);
}