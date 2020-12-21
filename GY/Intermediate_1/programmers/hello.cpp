#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<string> cache;
    int len = cities.size();
    for (int i = 0; i < len; i++)
    {
        transform(cities[i].cbegin(), cities[i].cend(), cities[i].begin(), ::tolower);
        if (cache.size() < cacheSize)
        {
            cache.push_back(cities[i]);
            answer += 5;
        }
        else
        {
            if (cacheSize == 0)
            {
                answer += 5;
            }
            else
            {
                if (find(cache.begin(), cache.end(), cities[i]) != cache.end())
                {
                    cache.erase(find(cache.begin(), cache.end(), cities[i]));
                    cache.push_back(cities[i]);
                    answer += 1;
                }
                else
                {
                    cache.erase(cache.begin());
                    cache.push_back(cities[i]);
                    answer += 5;
                }
            }
        }
    }
    return answer;
}