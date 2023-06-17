#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;

        unordered_map<int, int> umap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (umap.find(target - nums[i]) != umap.end())
            {
                // agar map me mil gya tih
                ans.push_back(i);
                ans.push_back(umap[target - nums[i]]);
                return ans;
            }
            umap[nums[i]] = i;
        }
        return ans;
    }
};