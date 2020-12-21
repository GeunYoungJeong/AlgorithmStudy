#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i = 0; i<completion.size(); i++)
    {
        participant.erase(find(participant.begin(), participant.end(), completion[i]));
    }
    return participant[0];
}