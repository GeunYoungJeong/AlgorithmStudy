#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, temp;
    scanf("%d", &n);
    vector <int> N;
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &temp);
        N.push_back(temp);
    }
    scanf("%d", &m);
    for(int i = 0; i<m; i++)
    {
        scanf("%d", &temp);
        if(find(N.begin(), N.end(), temp) == N.end()) printf("0\n");
        else printf("1\n");
    }    
}