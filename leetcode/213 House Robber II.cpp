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

// ��Ȼ�Ƕ�̬�滮
// ���ڵ�һ������������ѡ��
// 1. �������2�����һ�����ӱ�Ȼ���ܱ�����������Ҫ����ӵ��������ӵ��ڵ���
//    �ڶ������ӵ������ܲƸ�
// 2. ������������1�����һ�����ӵ��ܲƸ�
// �����������������ת��Ϊ ROB1 �Ķ�̬�滮����
// ���Ƚ�1��2�������ȡ���ֵ����
int rob(vector<int>& nums) {
	int n = (int)nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];
	if (n == 2) return max(nums[0], nums[1]);

	// 1. ����һ������
	vector<int> first_dp(n, 0);
	for (int i = 2; i <= n-2; ++i) {
		if (i == 2) first_dp[i] = nums[i];
		else if (i == 3) first_dp[i] = max(nums[i], nums[i-1]);
		else first_dp[i] = max(first_dp[i-1], first_dp[i-2]+nums[i]);
	}

	int ans1 = first_dp[n-2] + nums[0];
	
	// 2. ������һ������
	vector<int> no_first_dp(n, 0);
	for (int i = 1; i < n; ++i) {
		if (i == 1) no_first_dp[i] = nums[i];
		else if (i == 2) no_first_dp[i] = max(nums[i], nums[i-1]);
		else no_first_dp[i] = max(no_first_dp[i-1], no_first_dp[i-2]+nums[i]);
	}
	int ans2 = no_first_dp[n-1];

	return max(ans1, ans2);
}

int main()
{
	int a[] = {1, 3, 1};
	vector<int> v(a, a+3);
	cout << rob(v) << endl;
	return 0;
}