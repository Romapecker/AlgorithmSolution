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

// ��̬�滮��
// ���� dp[n] = ����n�����������������Ƹ�ͬʱ�����𾯱�
// ���һ������������ѡ��
// 1. ��������������£�ǰһ�����ӱ�Ȼ���ܱ���, �ܲƸ�=dp[n-2] + A[n]
// 2. ����������������£�ʵ���Ͼ�����n-1���ӵĲƸ�����dp[n-1]
// ����: dp[n] = max(dp[n-1], dp[n-2]+A[n])
int rob(vector<int>& nums) {
	int n = (int)nums.size();
	if (n == 0) return 0;
	
	vector<int> dp(nums.begin(), nums.end());
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			dp[i] = nums[i];
		} else if (i == 1) {
			dp[i] = max(nums[0], nums[1]);
		} else if (i >= 2) {
			dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
		}
	}

	return dp[n-1];
}