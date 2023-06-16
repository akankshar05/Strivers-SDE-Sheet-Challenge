#include <iostream>
#include <vector>
using namespace std;

struct eleCount
{
    int e; // Element
    int c; // Count
};

vector<int> moreThanNdK(vector<int> &nums, int n, int k)
{
    vector<int> result;
    if (k < 1)
        return result;

    if (k == 1)
    {
        for (auto i : nums)
        {
            auto it = find(result.begin(),
                           result.end(), i);
            if (it == result.end())
            {
                result.push_back(i);
            }
        }
        return result;
    }

    struct eleCount temp[k];
    for (int i = 0; i < k; i++)
        temp[i].c = 0;

    for (int i = 0; i < n; i++)
    {
        int j;

        for (j = 0; j < k; j++)
        {
            if (temp[j].e == nums[i])
            {
                temp[j].c += 1;
                break;
            }
        }

        if (j == k)
        {
            int l;

            for (l = 0; l < k; l++)
            {
                if (temp[l].c == 0)
                {
                    temp[l].e = nums[i];
                    temp[l].c = 1;
                    break;
                }
            }

            if (l == k)
                for (l = 0; l < k; l++)
                    temp[l].c -= 1;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (nums[j] == temp[i].e)
                ac++;

        if (ac >= n / k)
        {
            result.push_back(temp[i].e);
        }
    }

    return result;
}

int main()
{

    vector<int> vec = {1, 1, 2, 2, 3};

    int size = vec.size();
    int k = 1;
    vector<int> ans;
    ans = moreThanNdK(vec, size, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}