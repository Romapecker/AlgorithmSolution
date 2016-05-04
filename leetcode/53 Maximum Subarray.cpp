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
// ����dp[i] = ��i��β������������
//
// Claim 1:
// ��ô��i+1��β������������dp[i+1]��Ȼ��dp[i]+a[i+1]��a[i+1]�Ľϴ���
// ֤�����£�
// ���i+1�ƽ�β������������dp[i]��������ͼ*��ʾ�������Ĳ���ֻ��3�ֿ��ܣ�
// 1. ����Ĳ���Ϊ������ô��ʱdp[i]Ҳ��������ö��ಿ�֣���dp[i]�����Ž�ì�ܣ�
// 2. ����Ĳ���Ϊ������ʱ����ͨ���������ö��ಿ�ֵõ������dp[i+1]
// 3. ����Ĳ���Ϊ0����ʱ�������ö��ಿ��ͬ�����Եõ�����dp[i+1]
// [] [] [] [] [] [] [i] [i+1] []
//          +  +  +  + 
//    *  *  *  *  *  *   *
//             ^  ^  ^   ^
// Claim 2:
// ͬ��dp[i+1]��������Ҳ�����ܶ���dp[i], ��ͼ^��ʾ
// 1. ����ٵĲ���Ϊ����������ò��ֿ��Եõ������dp[i+1]
// 2. ����ٵĲ���Ϊ������dp[i]�����ų��ò��ֺ�õ������dp[i],��dp[i]������ì��
// 3. ����ٵĲ���Ϊ0����dp[i+1]�����ò��ֲ�Ӱ����
//
// ͨ��Claim1 �� Claim2���Ե�֪
// dp[i+1]�����ĳ��Ƚ��պõ���dp[i]�����ĳ���+1
// ����ȡdp[i]+nums[i+1]��nums[i+1]�����ֵ���ɵõ����Ž�
int maxSubArray(vector<int>& nums) {
	int n = (int)(nums.size());
	vector<int> dp(nums.begin(), nums.end());
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1]+nums[i], nums[i]);
	}

	int ans = nums[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, dp[i]);
	}

	return ans;
}

#if 0
int main()
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(a, a + 9);
	cout << maxSubArray(v) << endl;
	return 0;
}
#endif //0