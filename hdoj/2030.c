#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int i, j, k;
	int len;
	int cnt;
	char line[1024];
	
	scanf("%d\n", &n);
	for (i = 0; i < n; ++i) {
		gets(line);
		len = strlen(line);
		cnt = 0;
		j = 0;
		/* ���ֵĻ������������ֽڱ�ʾһ�����֣��������λ��Ϊ1�������ASCIIֵС��0
		   ������������ASCII���ʾһ������ */
		while (j < len) {
			if (line[j] > 0)
			{
				j++;
			} else if (line[j] < 0) {
				j += 2;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
