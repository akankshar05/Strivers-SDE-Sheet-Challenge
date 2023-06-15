#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }

        int k = 3;
        int size = k - 1;
        vector<int> candidates(size);
        vector<int> counts(size);
        for (int currentElem : nums)
        {
            bool moveToNextElem = false; // moveToNextElem indicates whether we are done with currentElem

            for (int i = 0; !moveToNextElem && i < size; i++)
            {
                if (currentElem == candidates[i])
                {
                    counts[i]++;
                    moveToNextElem = true;
                }
            }

            for (int i = 0; !moveToNextElem && i < size; i++)
            {
                if (counts[i] == 0)
                {
                    candidates[i] = currentElem;
                    counts[i]++;
                    moveToNextElem = true;
                }
            }

            for (int i = 0; !moveToNextElem && i < size; i++)
            {
                counts[i]--;
            }
        }

        // Validation
        fill(counts.begin(), counts.end(), 0); // Reinitialize counts
        for (int currentElem : nums)
        {
            for (int i = 0; i < size; i++)
            {
                if (currentElem == candidates[i])
                {
                    counts[i]++;
                    break;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < size; i++)
        {
            if (counts[i] > nums.size() / k)
            {
                result.push_back(candidates[i]);
            }
        }

        return result;
    }
};
