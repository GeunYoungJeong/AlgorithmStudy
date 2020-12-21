#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    bool state;
    while(true)
    {
        cin >> input;
        if(input == "0") return 0;
        state = true;
        for(int i = 0; i<input.size()/2; i++)
        {
            if(input[i] != input[input.size()-i-1]) state = false;
        }

        if(!state) printf("no\n");
        else printf("yes\n");
    }
}