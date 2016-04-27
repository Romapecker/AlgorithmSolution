#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


/**
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

int main()
{
	int ans = longestValidParentheses(")");
	cout << ans << endl;
	return 0;
}