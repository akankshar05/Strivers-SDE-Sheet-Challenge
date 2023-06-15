#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    double rec(double x, int n)
    {

        // for positive
        if (n == 1)
        {
            return x;
        }

        // for negative
        if (n == -1)
        {
            return x;
        }

        if (n % 2 == 0)
        {
            double ans = rec(x * x, n / 2);
            return ans;
        }

        double ans = rec(x * x, n / 2) * x;
        return ans;
    }
    double myPow(double x, int n)
    {
        if (x == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }

        if (n >= 0)
        {
            return rec(x, n);
        }

        return 1 / rec(x, n);
    }
};
