#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    vector<int> pocket;
    int len = moves.size();
    int s = board.size();

    for (int i = 0; i < len; i++)
    {
        int current = -1;
        for (int j = 0; j < s; j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                current = board[j][moves[i] - 1];
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
        if (current != -1)
        {
            if (!pocket.empty() && pocket.back() == current)
            {
                answer += 2;
                pocket.pop_back();
            }
            else
            {
                pocket.push_back(current);
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> board;
    board.push_back({ 0,0,0,0,0 });
    board.push_back({ 0,0,1,0,3 });
    board.push_back({ 0,2,5,0,1 });
    board.push_back({ 4,2,4,4,2 });
    board.push_back({ 3,5,1,3,1 });
    vector<int>move = { 1,5,3,5,1,2,1,4 };
    solution(board, move);
}