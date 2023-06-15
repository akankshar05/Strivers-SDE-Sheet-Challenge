#include <vector>
#include <set>
#include <iostream>
using namespace std;

long long merge(long long *nums, int low, int mid, int high)
{
    long long cnt = 0;

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
        if (arr1[i] <= arr2[j])
        {
            nums[k] = arr1[i];
            i++;
        }
        else
        {
            nums[k] = arr2[j];
            cnt += n1 - i;
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
long long mergesort(long long *nums, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (low >= high)
        return 0;

    long long ans = mergesort(nums, low, mid);
    ans += mergesort(nums, mid + 1, high);
    ans += merge(nums, low, mid, high);
    return ans;
}
long long getInversions(long long *arr, int n)
{
    return mergesort(arr, 0, n - 1);
}

int main()
{
    const int n = 6;
    long long arr[n] = {2, 5, 1, 1, 3, 4};

    cout << getInversions(arr, n) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}