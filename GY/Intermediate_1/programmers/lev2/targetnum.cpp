#include <bits/stdc++.h>

using namespace std;
int answer = 0;

void solve(int current, int current_idx, vector<int>numbers, int target)
{
    if(current_idx == numbers.size())
    {
        if(current == target) answer += 1;
        return;
    }

    solve(current + numbers[current_idx], current_idx+1, numbers, target);
    solve(current + numbers[current_idx] * -1, current_idx+1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    solve(0, 0, numbers, target);
    return answer;
}