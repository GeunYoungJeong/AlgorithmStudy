#include <bits/stdc++.h>

using namespace std;

vector <string> lang;
vector <string> part;
vector <string> career;
vector <string> food;
vector <string> score;

vector <vector<string>> l = {lang, part, career, food, score};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int n = info.size();
    for(int i = 0; i<n; i++) {
        string temp;
        int len = info[i].size();
        int k = 0;
        for(int j = 0; j<len; j++) {
            if(info[i][j] ==' ') {
                l[k].push_back(temp);
                temp = "";
                k++;
            }
            else {
                temp.push_back(info[i][j]);
            }
        }
        l[k].push_back(temp);
    }

    deque <int> deq_temp;
    for(int j = 0; j<n; j++) deq_temp.push_back(j);

    int m = query.size();
    for(int i = 0; i<m; i++) {	
        char *buffer = new char[1000];
	    strcpy(buffer, query[i].c_str());
	    char *tok = strtok(buffer, " ");
        int k = 0;
        deque <int> deq = deq_temp;
	    while(tok != NULL) {
            if(strcmp(tok ,"and") != 0) {
                if(strcmp(tok ,"-") != 0) {
                    if(k<4) {
                        int t = deq.size();
                        for(int j = 0; j<t; j++) {
                            int f = deq.front();
                            deq.pop_front();
                            if(strcmp(tok,l[k][f].c_str()) == 0) deq.push_back(f);
                        }
                    }
                    else {
                        int t = deq.size();
                        for(int j = 0; j<t; j++) {
                            int f = deq.front();
                            deq.pop_front();
                            if(stoi(tok, nullptr, 10) <= stoi(l[k][f], nullptr, 10)) deq.push_back(f);
                        }
                    }
                }
                k++;
            }
		    tok = strtok(NULL, " ");
	    }
        answer.push_back(deq.size());
    }
    return answer;
}

int main() {
    int n, m;
    string str;
    cin >> n >> m;
    vector <string> info, query;
    for(int i = 0; i<n; i++) {
        getline(cin, str, '\n');
        info.push_back(str);
        cin.ignore('\n');
    }

    for(int i = 0; i<n; i++) {
        getline(cin, str, '\n');
        query.push_back(str);
        cin.ignore('\n');
    }
    
    solution(info, query);


}