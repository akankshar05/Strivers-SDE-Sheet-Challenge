#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int c = mid % col;
            int r = mid / col;
            if (target < matrix[r][c])
            {
                high = mid - 1;
            }
            else if (target > matrix[r][c])
            {
                low = mid + 1;
            }
            else if (target == matrix[r][c])
            {
                return true;
            }
        }
        return false;
    }
};

// row is found by mid/col
// col is found by mid%col
