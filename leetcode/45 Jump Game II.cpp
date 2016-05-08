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

// �ֲ����Ծ�� BFS
// 2 3 1 1 4
// 2 || 3 1 || 1 4
// 2����������λ��Ϊ3, 1 ��3,1 ��������λ��Ϊ1, 4
int jump(vector<int>& nums) {
	int n = (int) nums.size();
	if (n <= 1) return 0;

	int current_max_jump = 0; // ��ǰ�������������λ��
	int last_max_jump = 0;    // ��һ���������������λ��
	int step_cnt = 0;         // ��Ծ����

	
	for (int i = 0; i < n - 1; ++i) {
		// ÿ�θ��µ�ǰλ�����ܵ�������λ��
		current_max_jump = max(current_max_jump, nums[i] + i);
		
		// �����������һ���ܴﵽ�����λ�ã�����һ����Ծ
		// ͬʱ������һ���������������λ��Ϊ��ǰ�Ѿ������������������������λ��
		if (i == last_max_jump) {
			step_cnt++;
			last_max_jump = current_max_jump;
		}
	}
	return step_cnt;
}

int main()
{
	int a[] = {2, 3, 1, 1, 4};
	vector<int> v(a, a + 5);
	cout << jump(v) << endl;
	return 0;
}