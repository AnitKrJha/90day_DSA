// Given an array of integers, find a pair with a given sum using a hash table in linear time.
// TC:O(N)
// map.find() has tc of O(logn) for ordered map and O(1) for unordered map.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main()
{

    vector<int> v = {70, 62, 55, 35, 75, 18, 38, 85, 98, 29, 46, 51, 46, 25, 85, 33, 7, 66, 66, 96, 49, 88, 20, 89, 2, 62, 50, 56, 37, 50, 48, 92, 78, 12, 1, 53, 39, 92, 51, 92, 67, 57, 1, 53, 5, 79, 54, 38, 32};
    int target = 140;
    unordered_map<int, int> m;

    vector<pair<int, int>> ans;

    for (int i = 0; i < v.size(); i++)
    {
        if (m.find(target - v[i]) != m.end())
        {
            ans.push_back({m[target - v[i]], i});
        }
        m.insert({v[i], i});
    }

    for (auto &x : ans)
    {
        cout << "{" << x.first << "," << x.second << "}\n";
    }

    if (ans.empty())
        cout << "NOpe\n";
}