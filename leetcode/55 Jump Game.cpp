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

// ̰���㷨
// ����ܵ�kλ�ã����Ȼ�ܵ�kǰ���λ��
bool canJump(vector<int>& nums) {
	int n = (int)nums.size();
	
	int cur = 0; // ��ǰλ��
	int maxCanReach = cur + nums[cur]; // ��ǰ���ܵ�������λ��
	while (cur < n && cur <= maxCanReach) { // ����û�ܵ����ÿһ��λ�ñ���
		maxCanReach = max(cur + nums[cur], maxCanReach); // �������λ��
		cur++;
	}
	return maxCanReach>=n-1;
}


#if 0
int main()
{
	int a[] = {2, 3, 1, 1, 4};
	int b[] = {3, 2, 1, 0, 4};
	vector<int> v1(a, a + 5);
	vector<int> v2(b, b + 5);

	cout << canJump(v1) << endl;
	cout << canJump(v2) << endl;
	
	return 0;
}
#endif //