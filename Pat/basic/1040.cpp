#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long llong;
const llong MOD = 1000000007;
const int MAX_N = 100010;
char s[MAX_N] = { '0' };
llong cntP[MAX_N]; // �������main��������Ϊ�ֲ���������� stackoverflow ���
llong cntT[MAX_N];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);
    llong ans = 0;

    for (int i = 0; i < MAX_N; ++i) cntP[i] = 0;
    for (int i = 0; i < MAX_N; ++i) cntT[i] = 0;

    // ����˼�룺����ÿһ�� A �ַ����ٶ�֪�� A ǰ���� nP ��P�ַ���A ������
    // nT �� T�ַ������Ը�A�ַ�Ϊ���ĵ�PAT�ַ����� nP * nT ����
    // ����ÿ��A�ַ�ǰ���P�ַ����Զ�������һ��ɨ�裬�������P���ǰһλ+1������
    // �����ǰһλ��P�������ɡ������ܵ�ʱ�临�Ӷȿ��Խ��� O(n)
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'P')
        {
            if (i - 1 >= 0) cntP[i] = cntP[i - 1] + 1;
            else cntP[i]++;
        }
        else
        {
            if (i - 1 >= 0) cntP[i] = cntP[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'T')
        {
            if (i + 1 < n) cntT[i] = cntT[i + 1] + 1;
            else cntT[i]++;
        }
        else
        {
            if (i + 1 < n) cntT[i] = cntT[i + 1];
        }

    }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'A')
        {
            ans = (ans % MOD + (cntP[i] * cntT[i]) % MOD) % MOD;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}