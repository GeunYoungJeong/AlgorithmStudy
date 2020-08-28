#include <bits/stdc++.h>

using namespace std;

bool b(string &first, string &second) {
    if(first.size() == second.size()) {
        return first < second;
    }
    return first.size() < second.size();
}

int main() {
    int s, t;
    scanf("%d %d", &s, &t);

    if(s==t) {
        printf("0\n"); return 0;
    }

    vector <string> result;
    queue <tuple<unsigned long long, string, int>> q;
    q.push(make_tuple(s, "", 0));
    
    while(!q.empty()) {
        int tnum;
        unsigned long long num; 
        string str;
        tie(num, str, tnum) = q.front();
        q.pop();
        // cout << num << " " << tnum << " " <<str << endl;

        if(num == t) {
            result.push_back(str);
        }
        else if(num > t) {
            //do nothing
            if(num != 0 && tnum == 0) q.push(make_tuple(0, str + "-", tnum + 1));
            if(tnum == 0) q.push(make_tuple(1, str + "/", tnum + 1));
        }
        else {
            //num < t
            if(num != pow(num, 2)) q.push(make_tuple(pow(num, 2), str + "*", tnum + 1));
            if(num != 0) q.push(make_tuple(2 * num, str + "+", tnum + 1));
            if(num != 0 && tnum == 0) q.push(make_tuple(0, str + "-", tnum + 1));
            if(tnum == 0) q.push(make_tuple(1, str + "/", tnum + 1));
        }
    }

    if(result.empty()) {
        printf("-1\n");
        return 0;
    }

    sort(result.begin(), result.end(), b);
    // for(int i = 0; i<result.size(); i++) {
    //     cout << result[i] << endl;
    // }
    cout << result[0] << endl;
    return 0;
}