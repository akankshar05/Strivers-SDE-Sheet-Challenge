/// similar tp count inversions:
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int temp = mid + 1;

        // merging
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int arr1[n1];
        int arr2[n2];
        for (int i = 0; i < n1; i++)
        {
            arr1[i] = nums[low + i];
        }
        for (int j = 0; j < n2; j++)
        {
            arr2[j] = nums[mid + j + 1];
        }

        int i, j, k;
        i = 0;
        j = 0;
        k = low;

        while (i < n1 && j < n2)
        {
            if (arr1[i] > 2LL * arr2[j])
            {
                cnt += n1 - i;
                j++;
            }
            else
            {
                i++;
            }
        }

        i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                nums[k] = arr1[i];
                i++;
            }
            else
            {
                nums[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            nums[k] = arr1[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            nums[k] = arr2[j];
            j++;
            k++;
        }
        return cnt;
    }
    int mergesort(vector<int> &nums, int low, int high)
    {
        int mid = low + (high - low) / 2;
        if (low >= high)
            return 0;

        int ans = mergesort(nums, low, mid);
        ans += mergesort(nums, mid + 1, high);
        ans += merge(nums, low, mid, high);
        return ans;
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int a = mergesort(nums, 0, n - 1);
        //    for (int i : nums){
        //        cout<<i<<" ";
        //    }

        return a;
    }
};