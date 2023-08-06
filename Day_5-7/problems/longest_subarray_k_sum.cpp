// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main()
{
    vector<int> v = {4, 6, 7, 1, 4, 0, 8};

    int target = 8;
    // 4 6 7 1 4 0 8 ,

    // Prefix Sum to length
    //  0  -> 0
    //  2  -> 1
    //  10 -> 2
    //  17 -> 3
    //  18 -> 4
    //  22 -> 5
    //  22 -> 6
    //  30 -> 7

    unordered_map<int, int> pf_sum_length;
    pf_sum_length[0] = 0;

    int sum = 0;
    int maxLen = -1;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (pf_sum_length.find(sum) == pf_sum_length.end())
            pf_sum_length.insert({sum, i + 1});
        if (pf_sum_length.find(sum - target) != pf_sum_length.end())
        {
            maxLen = max(maxLen, i + 1 - pf_sum_length[sum - target]);
        }
    }
    cout << maxLen;
}