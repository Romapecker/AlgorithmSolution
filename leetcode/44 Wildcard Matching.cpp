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

// ����dp[i][j]��ʾs[0...i]��p[0...j]�Ƿ�ƥ��
// 1. dp[i][j] = dp[i-1][j-1]  if p[j] != '*'
// 2. dp[i][j] = dp[i-1][j] || dp[i][j-1] if p[j] == '*' 
// ^^^^^^^^^^
// &&&&&&&*
// 2��ʾ������һ���ַ���*���������������һ�������*��ƥ���κ��ַ�
// ������ת��Ϊdp[i][j-1]�Ƿ�ƥ�䣻��һ�������*����ƥ��һ���ַ����������
// �£�dp[m][j-1] (0<=m<j)���ƥ�䣬���Ȼdp[i][j]Ҳƥ��
bool isMatch(string s, string p) {

	int n1 = (int)s.size();
	int n2 = (int)p.size();
	// dp[i][j]��ʾ����Ϊi��s�ͳ���Ϊj��p�Ƿ�ƥ��
	vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n1; ++i) dp[i][0] = false;
	for (int j = 1; j <= n2; ++j) {
		if (p[j-1] == '*') dp[0][j] = true;
		else break;
	}

	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (p[j-1] != '*') {
				dp[i][j] = (p[j-1] == '?' || p[j-1] == s[i-1]) && dp[i-1][j-1];
			} else if (p[j-1] == '*') {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}

	return dp[n1][n2];
}