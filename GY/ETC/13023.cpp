#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int n, m;
bool visit[2001];

void solve(int current, vector<vector<int>>list)
{
    if(visit[current]) return;

    visit[current] = true;
    for(int i = 0; i<list[current].size(); i++)
    {
        solve(list[current][i], list);
    }

    int count = 0;
    bool state = false;
    for(int i = 0; i<n; i++)
    {
        if(!visit[i])
        {
            state = false;
            count = 0;
        }
        else
        {
            state = true;
            if(state) count++;
            if(count == 4) answer = 1;
        }
    }
}

int main()
{
    
    int a, b;
    scanf("%d %d", &n, &m);
    bool visit[2001] = {false,};
    vector<vector<int>> list(n, vector<int>());
    list[0].erase(unique())
    for(int i = 0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        list[a].push_back(b);
        list[b].push_back(a);
    }
    
    for(int i = 0; i<n; i++)
    {
        solve(i, list);
        if(answer == 1) break;
    }
    printf("%d", answer);
}