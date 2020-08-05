#include <bits/stdc++.h>

using namespace std;

int room[1001][1001];
bool visit[1001][1001];
int mirror = 0;

int solve(int n)
{
    int dirc = 2;

    int i = 0;
    int j = 0;

    while (i >= 0 && i < n && j >= 0 && j < n)
    {
        if (room[i][j] == 1)
        {
            if(dirc % 2 == 0) dirc--;
            else dirc++;
        }
        else if (room[i][j] == 2)
        {
            dirc = 5 - dirc;
        }

        if (!visit[i][j] && room[i][j] != 0)
        {
            mirror++;
            visit[i][j] = true;
        }

        switch (dirc)
        {
        case 1:
        {
            i--;
            break;
        }
        case 2:
        {
            j++;
            break;
        }
        case 3:
        {
            i++;
            break;
        }
        case 4:
        {
            j--;
            break;
        }
        }


    }
    return 0;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        mirror = 0;
        scanf("%d", &n);

        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%1d", &room[i][j]);
            }
        }

        solve(n);
        printf("Case #%d\n%d\n", k, mirror);
    }
}