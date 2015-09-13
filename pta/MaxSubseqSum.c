#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* O(n^3) */
int MaxSubseqSum1(int a[], int n)
{
	int maxsum = 0;
	int i, j, k;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			int cursum = 0;
			for (k = i; k <= j; ++k) {
				cursum += a[k];
			}
			if (cursum > maxsum) {
				maxsum = cursum;
			}
		}
	}
	return maxsum;
}

/* O(n^2) */
int MaxSubseqSum2(int a[], int n, int* start, int* end)
{
	int i, j;
	/* ȫ�����Ǹ�������� */
	int allneg = 1;
	for (i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			allneg = 0;
			break;
		}
	}
	if (allneg) {
		*start = a[0];
		*end = a[n-1];
		return 0;
	}
	
	int maxsum = 0;
	int cursum = 0;
	*start = 0; // ��ʼ��Ϊ0���б�Ҫ���ܹ���Ч���������������0����� 
	*end = 0;
	for (i = 0; i < n; ++i) {
		cursum = 0;
		for (j = i; j < n; ++j) {
			cursum += a[j];
			if (cursum > maxsum) {
				maxsum = cursum;
				*start = a[i];
				*end = a[j];
			}
		}
	}
	return maxsum;
}

/*  Divide and conquer O(nlogn) */
int MaxSubseqSumRecur(int a[], int left, int right)
{
	if (left > right) return 0;
	if (left == right) return MAX(0, a[left]);

	int maxsum = 0;
	int leftsum = 0;
	int rightsum = 0;
	int mid = left + (right - left) / 2;
	leftsum = MaxSubseqSumRecur(a, left, mid);
	rightsum = MaxSubseqSumRecur(a, mid + 1, right);
	maxsum = MAX(leftsum, rightsum);

	int tmp1 = 0;
	int tmp2 = 0;
	int cursum = 0;
	int i;

	for (i = mid + 1; i <= right; ++i) {
		cursum += a[i];
		if (cursum > tmp1) {
			tmp1 = cursum;
		}
	}

	cursum = 0;
	for (i = mid; i >= left; --i) {
		cursum += a[i];
		if (cursum > tmp2) {
			tmp2 = cursum;
		}
	}

	maxsum = MAX(maxsum, (tmp1 + tmp2));
	return maxsum;
}

int MaxSubseqSum3(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	return MaxSubseqSumRecur(a, left, right);
}

/* O(n) �������㷨 */
int MaxSubseqSum4(int a[], int n, int* start, int* end)
{
	int i;
	/* �ж�ȫ�Ǹ�������� */
	int allneg = 1;
	for (i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			allneg = 0;
			break;
		}
	}
	if (allneg) {
		*start = a[0];
		*end = a[n-1];
		return 0;
	}
	
	int maxsum = 0;
	int cursum = 0;
	*start = 0;
	*end = 0;
	int startpos = 0;
	for (i = 0; i < n; ++i) {
		cursum += a[i];
		if (cursum > maxsum) {
			maxsum = cursum;
			*end = a[i];			// ���ָ�������кͣ�������ʼ����ֹλ�� 
			*start = a[startpos];
		}
		if (cursum < 0) {
			cursum = 0;				// ǰ������к͸������µ����Ϊ��һ��λ�� 
			startpos = i + 1;
		}
	}
	return maxsum;
}

#define MAXN 100000
int a[MAXN];
int i, n;

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}


	int start = 0, end = 0;
	int ans2 = MaxSubseqSum4(a, n, &start, &end);
	printf("%d %d %d\n", ans2, start, end);

	return 0;
}
