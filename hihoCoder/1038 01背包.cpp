#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXN 600
#define MAXM 100010

int need[MAXN];
int value[MAXN];
int dp[MAXN][MAXM];

int q0[MAXM];
int q1[MAXM];

// ����� 01��������
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &need[i], &value[i]);
	}
	
	// dp[i][j] = �����j�Ž���ѡ��ǰi����Ʒ����ȡ�õ�����ֵ
	// ���ڵ�i����Ʒֻ������ѡ�񣬲�ѡ�����ѡ��
    // �����ѡ���� dp[i][j] = dp[i-1][j]
    // ���ѡ��, �� dp[i][j] = dp[i-1][j-need[i]] + value[i];
	// ��ԭ����ȼ������ dp[N][M]
	// ��ʼ������ dp[i][0] = 0 dp[0][j] = 0
	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	for (int j = 0; j <= m; ++j) dp[0][j] = 0;
	
	// ʱ��Ϳռ临�ӶȾ�Ϊ O(nm)
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j >= need[i]) {
				dp[i][j] = max(dp[i-1][j-need[i]] + value[i], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	printf("%d\n", dp[n][m]);

	
	// ������һ�еļ��������������һ��, ���Կ���ֻ�������ڴ洢���������ʹ��
	// ����ע�͵��Ĵ����ǿռ临�Ӷ�Ϊ O(2 * m),
	/*
	for (int j = 0; j <= m; ++j) {
		q0[j] = 0;
		q1[j] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i % 2 == 1) {
				if (j >= need[i]) {
					q1[j] = max(q0[j-need[i]] + value[i], q0[j]);
				} else {
					q1[j] = q0[j];
				}
			} else {
				if (j >= need[i]) {
					q0[j] = max(q1[j-need[i]] + value[i], q1[j]);
				} else {
					q0[j] = q1[j];
				}
			}
		}
	}
	int ans = (n % 2 == 1 ? q1[m] : q0[m]);
	printf("%d\n", ans);
	*/
	
	return 0;
}
