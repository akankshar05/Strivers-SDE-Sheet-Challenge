/*You are required to complete this function*/
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &a, int n)
    {

        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum == 0)
            {
                count = i + 1;
            }
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    // map me mil gya toh
                    count = max(count, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }
        return count;
        // Your code here
    }
};