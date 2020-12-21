#include <bits/stdc++.h>

using namespace std;

int l_column = 0, l_row = 3, r_column = 2, r_row = 3;    
string answer = "";

void push(char ch, int num) {
    answer.push_back(ch);
    if(ch =='R') {
        r_row = (num-1) / 3;
        r_column = (num-1) % 3;
        if(num == 0) {
            r_row = 3;
            r_column = 1;
        }
    }
    else {
        l_row = (num-1) / 3;
        l_column = (num-1) % 3;
        if(num == 0) {
            l_row = 3;
            l_column = 1;
        }
    }
}

string solution(vector<int> numbers, string hand) {
    int s = numbers.size();
    for(int i = 0; i<s; i++) {
        if(numbers[i] == 0 || numbers[i] % 3 == 2) {
            int row = (numbers[i]-1) / 3;
            int column = (numbers[i]-1) % 3;
            if(numbers[i] == 0) {
                row = 3; column = 1;
            }
            int left_distance = abs(row - l_row) + abs(column - l_column);
            int right_distance = abs(row - r_row) + abs(column - r_column);
            if(left_distance == right_distance) {
                if(hand == "right") push('R', numbers[i]);
                else push('L', numbers[i]);
            }
            else if(left_distance < right_distance) push('L', numbers[i]);
            else push('R', numbers[i]);
        }
        else if(numbers[i] % 3 == 1) push('L', numbers[i]);
        else push('R', numbers[i]);
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    vector <int> arr(n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    cout << solution(arr, "right");
    return 0;
}