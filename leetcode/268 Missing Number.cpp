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


// �ⷨһ��
// �������������ͣ����ܺ�-�����
#if 0
int missingNumber(vector<int>& nums) {
	long long sum = 0;
	for (size_t i = 0; i < nums.size(); ++i) {
		sum += nums[i];
	}

	int n = nums.size();
	long long temp = (long long)(n+1) * (long long)n / 2;

	return temp - sum;
}
#endif //0

// �ⷨ��
// 1. ������ɨ��ÿһ�����֣�����[0, n-1]֮���Ԫ�أ�����ݹ�ķ��õ���ȷ��λ��
// 2. �ڶ���ɨ�裬λ��i��Ԫ��nums[i]Ӧ�õ���i��������ȱ��Ԫ��i
// 3. ����ڶ���ɨ�����ȫ��Ԫ�ض�����ȷ��λ�ã����Ȼȱ��Ԫ��n
int missingNumber(vector<int>& nums) {
	int n = (int)nums.size();

	for (int i = 0; i < n; ++i) {
		int target = nums[i];
		while (target >= 0 && target < n && target != nums[target]) {
			int new_target = nums[target];
			nums[target] = target;
			target = new_target;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i != nums[i]) {
			return i;
		}
	}
	return n;
}

// Test
#if 0
int main()
{
	int a[] = {0, 1, 2};
	vector<int> v(a, a + 3);
	cout << missingNumber(v) << endl;
	return 0;
}
#endif //