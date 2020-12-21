#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int sum = 0;
    int input[5];
    for(int i = 0; i<5; i++)
    {
        scanf("%d", &input[i]);
        sum += (input[i] * input[i]);
    }
    printf("%d\n", sum%10);
}