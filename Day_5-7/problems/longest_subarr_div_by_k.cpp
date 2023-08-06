#include <iostream>
#include <unordered_map>
#include <vector>

int longestSubarrayWithSumDivisibleByK(const std::vector<int> &nums, int K)
{
    std::unordered_map<int, int> hashTable;
    int max_length = 0;
    int current_sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        current_sum += nums[i];
        int remainder = current_sum % K;

        if (remainder < 0)
        {
            remainder += K;
        }

        if (remainder == 0)
        {
            max_length = i + 1;
        }
        else if (hashTable.find(remainder) != hashTable.end())
        {
            max_length = std::max(max_length, i - hashTable[remainder]);
        }
        else
        {
            hashTable[remainder] = i;
        }
    }

    return max_length;
}

int main()
{
    // Example usage:
    std::vector<int> nums = {35, 2, -40, 21, 14, -9, -2, -31, 43, -40, -34, 33, 42, -8, 39, -10, -3, 9, -39, 9, 25, 39, -29, -4, -16, -36, 14, -9, -1, -10, -17, -43, -29, -2, 22, 20, -9, -25, -38, -15, -19, 30, -41, 17, -50, 35, 19, -18, -40};
    int K = 5;

    int result = longestSubarrayWithSumDivisibleByK(nums, K);
    std::cout << "Longest subarray length with sum divisible by " << K << ": " << result << std::endl;

    return 0;
}
