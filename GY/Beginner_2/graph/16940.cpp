/**
 * 5�ð����� Ǯ������
 * �㹫�� ���
 * �������� 1�� �ƴϸ� ��� ã���� �ø����� ����
 * �׳� �������� 1�� �ƴ� ��� ��ü�� ���� �ȵ�(�������� �׷��� ����)
 * �׳� �ȵȴٰ� ����ϸ� �� ��,,
 **/

#include <bits/stdc++.h>

using namespace std;

vector<int> check;
bool visit[100001];
vector <int> LIST[100001];

int main() {
    int n, a, b;
    scanf("%d", &n);

    int num = n-1;
    while(num--) {
        scanf("%d %d", &a, &b);
        LIST[a].push_back(b);
        LIST[b].push_back(a);
    }
    num = n;
    
    while(num--) {
        scanf("%d", &a);
        check.push_back(a);
    }

    if(LIST[1].size() == 0 || check[0] != 1) {
        printf("0\n");
        return 0;
    }

    queue <int> q;
    q.push(1);
    visit[1] = true;

    int s, e;
    s = e = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        vector <int> temp;

        for(int i = 0; i<LIST[x].size(); i++) {
            if(!visit[LIST[x][i]]) {
                visit[LIST[x][i]] = true;
                temp.push_back(LIST[x][i]);
            }
        }

        int S = temp.size();
        e += S;
        if(e <= n) {
            for(int i = s; i < e; i++) {
                bool c = true;
                for(int j = 0; j < S; j++) {
                    if(check[i] == temp[j]) {
                        q.push(check[i]);
                        c = false;                    
                    }
                }
                if(c) {
                    printf("0\n");
                    return 0;
                }
            }
        }
        s = e;
    }
    printf("1\n");
    return 0;
}