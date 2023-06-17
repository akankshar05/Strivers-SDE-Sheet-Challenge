#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = -1;
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        int max = INT_MIN;
        int count = 0;
        vector<int> vec(300, -1);
        for (int i = 0; i < len; i++)
        {
            if (start < vec[s[i]])
            {
                start = vec[s[i]];
            }
            vec[s[i]] = i;
            count = i - start;

            if (max < count)
            {
                max = count;
            }
        }

        return max;
    }
};