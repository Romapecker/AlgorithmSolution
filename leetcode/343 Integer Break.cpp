// ��̬�滮��
// n ���Է�Ϊx �� n-x�����֣����������ֵ����˻���Ȼ������˼���
// �� dp[n] = max_{x} dp[x] * dp[n-x]  ����x=1,2,3...sqrt(n)
// ����dp[n] ��ʾdp[n]�����ָ�����ܵõ������˻�
// dp[1] = 1; dp[2] = 1;
int integerBreak(int n) {
    vector<int> dp(n+1, 1);
    dp[1] = 1; // Ϊ�������ǿ�ƹ涨
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = 1 * (i-1);
        for (int k = 1; k <= i-1; ++k) {
            dp[i] = max(dp[i], max(k, dp[k]) * max(i-k, dp[i-k])); // note the special case which means that k may not break any more
        }
    }
    return dp[n];
}
