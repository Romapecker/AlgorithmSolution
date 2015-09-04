#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iterator>
using namespace std;

int partition(vector<int> &nums, int left, int right) {
    assert(left <= right);
    int pivot = nums[right];
    int i = left - 1;
    int j = left;
    for (j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            i += 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[j]);
    return i + 1;
}

int FindKth(vector<int>& nums, int left, int right, int k)
{
    // midֻ��[left,right]���ֵ���������Ӧ�ڵ� (mid - left) ��Ԫ��
    int mid = partition(nums, left, right);
    int rank = mid - left; // ���ֺ󣬻���λ�����ڵ� rank λ
    if (k == rank) {
        return nums[mid];
    } else if (k < rank) {
        return FindKth(nums, left, mid - 1, k);
    } else {
        return FindKth(nums, mid + 1, right, k - rank - 1);
    }
}

/**
* @param nums: A list of integers.
* @return: An integer denotes the middle number of the array.
*/
int median(vector<int> &nums) {
    int n = nums.size();
    return FindKth(nums, 0, n - 1, (n - 1) / 2);
}

// ע�⻮��λ�õ���λֵ rank �� k �Ƚϣ������ǻ���λ�ñ����� k �Ƚ�

#if 0
int main()
{
   // int a[] = { 4, 2};
    int b[] = { -1, -2, -3, -100, -1, -50 };

    //vector<int> v1(a, a + 2);
    vector<int> v2(b, b + 6);

    //cout << median(v1) << endl;
    cout << median(v2) << endl;
    return 0;
}
#endif //0