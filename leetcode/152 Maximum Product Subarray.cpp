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
// ���������������⣬ֻ�����˴����ֵ��ȡ�ã�Ҫ�Ƚ�
// max[i-1]*nums[i], min[i-1]*nums[i] �� nums[i] ���ߵ�������Сֵ
// ��Ϊ���ֵ����Сֵ
int maxProduct(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> maxProdEndHere(nums.begin(), nums.end());
	vector<int> minProdEndHere(nums.begin(), nums.end());

	for (int i = 1; i < n; ++i) {
		if (nums[i] > 0) {
			maxProdEndHere[i] = max(maxProdEndHere[i-1] * nums[i], nums[i]);
			minProdEndHere[i] = min(minProdEndHere[i-1] * nums[i], nums[i]);	
		} else if (nums[i] < 0) {
			maxProdEndHere[i] = max(minProdEndHere[i-1] * nums[i], nums[i]);
			minProdEndHere[i] = min(maxProdEndHere[i-1] * nums[i], nums[i]);
		} else if (nums[i] == 0) {
			minProdEndHere[i] = maxProdEndHere[i] = 0;
		}
	}

	int ans = maxProdEndHere[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, maxProdEndHere[i]);
	}
	return ans; 
}

int main()
{
	int a[] = {-2, 3, -2};
	vector<int> v(a, a + 3);
	cout << maxProduct(v) << endl;
	return 0;
}