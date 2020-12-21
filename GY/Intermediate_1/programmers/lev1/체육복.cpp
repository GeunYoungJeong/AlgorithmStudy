#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> c(n, 1);
    for(int i = 0; i<reserve.size(); i++)
    {
        c[reserve[i]-1]++;
    }
    
    for(int i = 0; i<lost.size(); i++)
    {
        c[lost[i]-1]--;
    }
    
    for(int i = 0; i<n; i++)
    {
        if(c[i] == 0)
        {
            if(i==0)
            {
                if(c[i+1] == 2)
                    c[i+1]--;
                else
                    answer--;
            }
            else if(i==n-1)
            {
                if(c[i-1] != 2)
                    answer--;
            }
            else
            {
                if(c[i-1] != 2)
                {
                    if(c[i+1] == 2)
                        c[i+1]--;
                    else
                        answer--;
                }
            }
        }
    }
    return answer;
}