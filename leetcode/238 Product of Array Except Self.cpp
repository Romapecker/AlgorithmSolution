#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// ǰ׺���顢��׺�����㷨
// ��������������˱������Ӷ��õ����������O(n)�Ŀռ临�Ӷ�
// ���㷨ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
vector<int> productExceptSelf(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> output(nums.begin(), nums.end());
	
	// output[i]���nums[0]*nums[1]*...*nums[i-1]
	int f = 1; // ��ǰ������ۻ�
	for (size_t i = 0; i < nums.size(); ++i) {
		if (i == 0) {
			output[i] = 1;
		} else {
			output[i] = f * nums[i-1];
			f *= nums[i-1];
		}
	}

	// ���ȼ���[i]λ��֮����ۻ�nums[n-1]*nums[n-2]...*nums[i+1]
	int b = 1; // �Ӻ�֮ǰ���ۻ�
	for (int j = n - 1; j >= 0; --j) {
		if (j == n - 1) {
			output[j] *= b;
		} else {
			output[j] *= b * nums[j+1];
			b *= nums[j+1];
		}
	}

	return output;
}

#if 0
int main()
{
	int a[] = {1, 2, 3, 4};
	vector<int> v(a, a + 4);
	vector<int> ans = productExceptSelf(v);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}
#endif //0