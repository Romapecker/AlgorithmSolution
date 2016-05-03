#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int n = (int)nums.size();

	// ��������һ�����������飬�������������0ֱ�Ӻ��ԣ�
	// ���򣬽�����k��������ȷ�ĵ�k-1��λ�ã�Ȼ��ݹ�ķ��õ�k-1λ�õ�����
	for (int i = 0; i < n; ++i) {
		int target = nums[i];
		while (0 < target && target <= n && target != nums[target-1]) {
			int new_target = nums[target-1];
			nums[target-1] = target;
			target = new_target;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] != i+1) {
			return i+1;
		}
	}

	return n+1;
}

#if 0
int main()
{
	int a[] = {2, 1};
	vector<int> v(a, a+2);
	cout << firstMissingPositive(v) << endl;
	return 0;
}
#endif //0