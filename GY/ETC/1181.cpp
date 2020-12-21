#include <bits/stdc++.h>
using namespace std;

bool compare(string first, string second)
{
    if (first.size() < second.size())
    {
        return true;
    }
    else if (first.size() == second.size())
    {
        return first < second;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector <string> v;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}