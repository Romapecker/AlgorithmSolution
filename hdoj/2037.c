#include <stdio.h>
#include <stdlib.h>

typedef struct tagItem {
	int Ti_s;
	int Ti_e;
} Item;

Item A[110];
int ItemCmp(const void* a, const void* b);
int MaxItemCanSee(Item* A, int n);

int main()
{
	int n, ans;
	register int i;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; ++i) {
			scanf("%d %d", &(A[i].Ti_s), &(A[i].Ti_e));
		}
		ans = MaxItemCanSee(A, n);
		printf("%d\n", ans);
	}
	return 0;
}

int ItemCmp(const void* a, const void* b)
{
	const Item* pa = (Item*)a;
	const Item* pb = (Item*)b;
	if (pa->Ti_e != pb->Ti_e) {
		if (pa->Ti_e < pb->Ti_e) return -1;
		else return 1;
	} else {
		if (pa->Ti_s > pb->Ti_s) return -1;
		else return 1;
	}
}

/* ̰���㷨�����ս�Ŀ������ʱ���������ͬʱ������̽�Ŀ���ȣ���ÿ��ѡ��ǰ��Ŀ
 * �����ǰ��Ľ�Ŀ���ص���ֱ������ */
int MaxItemCanSee(Item* A, int n)
{
	register int i;
	int cnt = 1;
	int lasttime;
	qsort(A, n, sizeof(Item), ItemCmp);
	
	lasttime = A[0].Ti_e;
	for (i = 1; i < n; ++i) {
		if (A[i].Ti_s < lasttime) {
			continue;
		} else {
			cnt++;
			lasttime = A[i].Ti_e;
		}
	}
	return cnt;
}
