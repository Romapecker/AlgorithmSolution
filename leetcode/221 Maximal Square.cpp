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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// ��naive�Ľ���������ִ����š��ص������⡿����˿����Ƿ����ö�̬�滮
// ���н�������������ĳ��Է��֣���ǰλ�õġ�ȫ1���󡱣����¼�ơ����󡱣��ı߳�
// ȡ����ǰ���ڵ�����λ�õı߳�ֵ�������
// ���塡dp[i][j] = ��i��jλ��Ϊ�������½ǽ�β�ķ���ı߳�
// �� dp[i][j] = 1  if A[i-1][j-1] = 0 ���� A[i][j-1] = 0 ���� A[i-1][j] = 0
// dp[i][j] = min{A[i-1][j-1], A[i][j-1], A[i-1][j]} + 1
// �Ӷ�����õ����

int maximalSquare(vector<vector<char>>& A) {
    if (A.empty()) return 0;
    int m = (int)A.size();
    int n = (int)(A[0].size());
        
    int ans = 0;
        
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) { dp[0][j] = (A[0][j] - '0'); ans = max(ans, dp[0][j]); }
    for (int i = 0; i < m; ++i) { dp[i][0] = (A[i][0] - '0'); ans = max(ans, dp[i][0]); }
        
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (A[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                if (A[i-1][j-1] == '0' || A[i-1][j] == '0' || A[i][j-1] == '0') {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                }
            }
            ans = max(ans, dp[i][j]);
                
        }
    }
        
    return ans * ans;     
}