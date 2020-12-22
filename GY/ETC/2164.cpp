#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp;
    scanf("%d", &n);
    queue<int>card;
    for(int i = 0; i<n; i++) card.push(i+1);
    while(card.size()!=1)
    {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    printf("%d", card.front());
}