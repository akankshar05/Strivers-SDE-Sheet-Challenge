#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int i = 0;
        int j = 1;
        int ans = INT_MIN;

        while (j != prices.size())
        {
            if (prices[i] < prices[j])
            {
                int profit = prices[j] - prices[i];

                ans = max(ans, profit);
            }
            else
            {
                i = j;
            }
            j++;
        }
        if (ans < 0)
        {
            return 0;
        }
        return ans;
    }
};
