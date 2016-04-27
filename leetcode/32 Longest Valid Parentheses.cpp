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


#if 0
/**
 * �ⷨһ������ƥ��
 * 1. ��������ɨ�������ַ���
 * 2. ������������ţ���ջ��
 * 3. ������������ţ����ջ������ջ��Ϊ�����ţ���ջ�����������Ž�ջ
 * 4. ����ʱ����ջΪ�գ��������ַ����Ϸ�
 * 5. ����ջ�д�����зǷ����ŵ�λ�ã�����Ƿ�λ���м�����г��ȣ�ȡ��󳤶�
 */

int longestValidParentheses(string s) {
	int n = (int)s.size();
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		// ���������ţ�������ջ
		if (s[i] == '(') {
			st.push(i);
	    // ����������
		} else {
			// ���ջ��Ϊ�����ţ�ƥ�䣬��ջ
			if (!st.empty() && s[st.top()] == '(') {
				st.pop();
			} else { // �������ջ��ҲΪ�����ţ���ջ
				st.push(i);
			}
		}
	}

	int longest = 0;
	// ���ջ�գ��������ַ�����ȫƥ��
	if (st.empty()) {
		return n;
	} else {
		// ���ҵ���Ѱ�����ų���
		int right = n;
		int left = 0;

		// left λ�ò�ƥ�䣬��(left, right)֮���Ȼƥ��
		while (!st.empty()) {
			left = st.top();
			st.pop();
			longest = max(longest, right-left-1);
			right = left;
		}

		// �˳�loopʱ��rightָ���һ����ƥ��λ�ã���Ҫ����[0, right)֮��ƥ��ĳ���
		longest = max(longest, right);

		return longest;
	}
}
#endif //0

/**
 * �ⷨ������̬�滮
 * ����dp[i] = ��i��β�������Ч����ƥ�䳤��
 * �����ǰ�������ţ���dp[i] = 0
 * �����ǰ�������ţ�����ǰһ��λ����������,��dp[i] = 2 + dp[i-2] // ����ͼpos = 5
 * ���������ǰ�������ţ�ǰ��һ��Ҳ�������� (��pos=6),��dp[i-1]��ʾǰһ���Ѿ�ƥ���
 * ���ȣ���Ҫ�鿴i-dp[i-1]-1��λ�ã�pos=1������������ţ���Ҳ��ƥ�䵽��������������2��
 * ͬʱ��Ҫ���ϸ�λ��֮ǰ��ƥ�䳤�ȣ���dp[i-dp[i-1]-2],
 * ���ϣ�dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2]
 * ��Ҫע����������λ�ñ�����ڵ���0
 * 
 * /// ʾ��ͼ
 * ) ( ( ) ( ) )
 * 0 1 2 3 4 5 6
 */

int longestValidParentheses(string s) {
	int n = int(s.size());
	vector<int> dp(n, 0);
	int longest = 0;
	for (int i = 1; i < n; ++i) {
		// ����������ţ������ܴ����������Ž�β����Ч��������
		if (s[i] == '(') {
			dp[i] = 0;
		} else {
			if (i - 1 >= 0 && s[i-1] == '(') {
				dp[i] = 2 + (i-2 >= 0 ? dp[i-2]:0);
				longest = max(longest, dp[i]);
			} else if (i - 1 >= 0 && s[i-1] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
				dp[i] = 2 + dp[i-1] + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
				longest = max(longest, dp[i]);
			}
		}
		//cout << "dp[" <<i << "] = " << dp[i] << endl;
	}
	return longest;
}

int main()
{
	int ans = longestValidParentheses(")(()())");
	cout << ans << endl;
	return 0;
}