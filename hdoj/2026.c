#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 256
int main()
{
	char line[MAX_LINE_LEN];
	int i, j, k;
	int n;
	while (gets(line) != NULL) {
		n = strlen(line);
		i = 0;
		while (i < n) {
			while (i < n && line[i] == ' ') i++;    /* �����ո� */
			if (i >= n) break;
			if (isalpha(line[i]) && islower(line[i])) {
				line[i] = toupper(line[i]);
				i++;
			}
			while (i < n && line[i] != ' ') i++;    /* �����õ��ʵ��������� */
			if (i >= n) break;
		}
		printf("%s\n", line);
	}
	return 0;
}
