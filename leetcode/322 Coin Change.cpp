// ����DP����
// [a0, a1, a2, ... an-1] to x
// ����dp[i][j]=��[a0,a1,...,ai]�һ�j��������Ǯ��Ҫ������Ӳ������
// ������һ��Ӳ�������������ʹ�û��߲�ʹ��
// ʹ�õĻ� dp[i][j] = dp[i][j-a[i]] + 1 ����ʹ��һ��a[i]
// ��ʹ�õĻ� dp[i][j] = dp[i-1][j]
// ȡ���ߵ���Сֵ���ɣ�ע�⿼�����ߵ�ֵ�Ƿ�Ϊ-1��ʾ���ܶһ�
int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) return 0;

    sort(coins.begin(), coins.end());
    int n1 = (int) coins.size();
    int n2 = amount;

    vector<vector<int>> dp(n1, vector<int>(n2+1, 0));
    // base case 1
    for (int j = 0; j <= n2; ++j) {
        if (j < coins[0] || j % coins[0] != 0) {
            dp[0][j] = -1;
        } else {
            dp[0][j] = j / coins[0];
        }
    }

    // base case 2
    for (int i = 0; i < n1; ++i) {
        dp[i][0] = 0;
    }

    dp[0][0] = 0;

    // bottom to up
    for (int i = 1; i < n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (j < coins[0]) {
                dp[i][j] = -1;
            } else {
                if (j >= coins[i]) {
                    int temp1 = dp[i][j-coins[i]];
                    int temp2 = dp[i-1][j];
                    if (temp1 == -1 && temp2 == -1) {
                        dp[i][j] = -1;
                    } else if (temp1 != -1 && temp2 == -1) {
                        dp[i][j] = temp1 + 1;
                    } else if (temp1 == -1 && temp2 != -1) {
                        dp[i][j] = temp2;
                    } else {
                        dp[i][j] = min(temp1+1, temp2);
                    }
                } else {
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
    }

    return dp[n1-1][n2];
}
