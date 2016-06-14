#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ
// ���Ӵ�С�������飬Ȼ���зֳ��������֣�ǰ�벿��Ϊlarger�����
// ����Ϊsmaller��Ȼ��larger��������λ�ã���smallerԪ�ط���ż��λ��
// ʱ�临�Ӷ� O(nlogn), �ռ临�Ӷ� O(n)
void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = (int) nums.size();
    vector<int> larger(nums.begin(), nums.begin() + n/2);
    vector<int> smaller(nums.begin()+n/2, nums.end());

    int i = 0; int j = 0;
    for (int k = 0; k < n; ++k) {
        if (k % 2 == 0) {
            nums[k] = smaller[i++];
        } else {
            nums[k] = larger[j++];
        }
    }

    return;
}

// ������:
// ����һ��ʱ�临�Ӷȹ��ߣ���Ҫ�����������O(nlogn)����ʵ�������ǲ�����Ҫ
// ������ȫ����ֻ��Ҫ������λ���Ϸű���λ�����������λ������ż��λ���Ϸ�
// ��λ���ͱ���λ��С�������ɣ���˿�����O(n)��ʱ��������һ��partition
// ����һ�пռ临�Ӷȵ�O(n)��Ҫ��������Ҫ�������������һ��λ���ٷ��䣬�������
// Index Mapping����������partition���������λ���ٷ��䣬�Ӷ���С���Ӷ�ΪO(1)
void wiggleSort(vector<int>& nums) {
    int n = (int) nums.size();
    nth_element(nums.begin(), nums.begin()+n/2, nums.end());
    int medium = nums[n/2];
    
    // Virtual Index Mapping
    #define nums(i) nums[(2*i+1) % (n|1)]
    
    // three way partitions,[>medium][==medium][<medium]
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
        if (nums(j) > medium) {
            swap(nums(i), nums(j));
            i++;
            j++;
        } else if (nums(j) < medium) {
            swap(nums(j), nums(k));
            k--;
        } else {
            j++;
        }
    }
}
