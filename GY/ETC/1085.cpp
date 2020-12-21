#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", min({x, w-x, h-y, y}));
}