#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            int sum = 0 - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] > sum)
                {
                    k--;
                }
                else if (nums[j] + nums[k] < sum)
                {
                    j++;
                }
                else
                {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                    k--;
                    j++;
                }
            }
        }
        return result;
    }
};