#include <bits/stdc++.h>

using namespace std;

int main() {
    setbuf(stdout, NULL);
    int t, n;
    unsigned long long m;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        scanf("%d %lld", &n, &m);
        vector <long long> a(n);
        vector <long long> psum(n);
        vector <long long> d(n);
        for(int j = 0; j<n; j++) {
            scanf("%lld", &a[j]);
            if(j==0) {
                psum[j] = a[j];
                d[j] = a[j];
            }
            else {
                psum[j] = psum[j-1] + a[j];
                (d[j - 1] + a[j] > a[j] ? d[j] = d[j - 1] + a[j] : d[j] = a[j]);
            }
        }


	    // for (int j = 0; j < n; j++) {
        //     printf("%lld\n", psum[j]);
	    // }
        long long answer = 0LL;
	    // for (int j = 0; j < n; j++) {
		//     if (d[j] >= 0 && d[j] <= m && d[j] > answer) answer = d[j];
	    // }
        // printf("Case #%d\n%lld\n", i, answer);
	    // for (int j = 0; j < n; j++) {
        //     //part 1
        //     if(answer < psum[j] && psum[j] <= m) answer = psum[j];
        //     //part 2
        //     if(answer < psum[n-1] - psum[j] && psum[n-1] - psum[j] <= m) answer = psum[n-1] - psum[j];
	    // }

        for(int j = 0; j<n; j++) {
            for(int k = j; k<n; k++) {
                long long temp = max({psum[j], psum[k] - psum[j], psum[n-1]-psum[k]});
                if(answer < temp && temp <= m) answer = temp;
            }
        }        

        // int p1 = 0, p2 = 0;

        // // p1�� p2�� ����, p1�� n�� ������ ��찡 �ƴ� ��쿡 while
        // while (!(n-1 == p1 && p1 == p2))
        // {
        //     // p1~p2������ ���� s���� ũ�ų� ������
        //     if (psum[p2] - psum[p1-1] >= answer )
        //     {
        //         if(psum[p2] - psum[p1-1] < m) {
        //             answer = psum[p2] - psum[p1-1];
        //         }
        //         // ���̸� �����ְ� �ּ� ���̸� �����ش�.
        //         p1++;
        //     }
 
        //     // p1~p2������ ���� s���� ������
        //     else if (psum[p2] - psum[p1 - 1] < answer)
        //     {
        //         // p2�� ���� �������� �������� �ʾҴٸ� p2++��, 
        //         // �� �ܿ��� p1++�� �Ѵ�.
        //         if (p2 < n-1)
        //             p2++;
        //         else
        //             p1++;
        //     }
        // }

        printf("Case #%d\n%lld\n", i, answer);
    }
    return 0;
}