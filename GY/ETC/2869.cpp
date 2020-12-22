#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, v, current, day;
    current = day = 0;
    scanf("%d %d %d", &a, &b, &v);
    while(current < v)
    {
        day++;
        current += a;
        if(current >= v) break;
        current -= b;
    }    
    printf("%d", day);
}