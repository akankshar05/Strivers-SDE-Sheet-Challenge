// more than n/2 times : then that will be only one element

#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int e = 0; // any num
        int c = 0;

        for (auto i : nums)
        {
            if (i == e)
            {
                c++;
            }
            else if (c == 0)
            {
                e = i;
                c = 1;
            }

            else
            {
                c--;
            }
        }

        return e;
    }
};