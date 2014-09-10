/*
 * ����������
 * ����һ��cube���˸��������xyz����ϵ�У����ұ�֤�˸����������ֵΪ
 * ���������ڶ�ÿһ�������������������permutation�����Ƿ��ܹ�������
 * ȷ��֮ǰ��cube�Ķ������꣬�������print�κ�һ�����н�
 *
 * ����˼·��
 * ��ÿ�������������ȫ��permutation�������ܹ�����configuration������
 * ÿһ��configuration����������������֮��ľ��룬ÿһ���㵽����7����
 * �ľ���ƽ��Ӧ��������3��ΪI��3��Ϊ2*I��1��Ϊ3*I��������ж��㶼������
 * �������������configuration������cube����֮������������㣬����
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long llong;

llong a[8][3];
llong b[7];

// ���㶥��i��j֮��ľ���ƽ��
llong dist(int i, int j)
{
    llong dx = a[i][0] - a[j][0];
    llong dy = a[i][1] - a[j][1];
    llong dz = a[i][2] - a[j][2];
    return dx * dx + dy * dy + dz * dz;
}

// ����һ�ָ�����configuration������8�����Ƿ��������
// �������������һ�����㵽��������ľ��벻����������
// ��false�� ����true
bool check()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (j < i) b[j] = dist(i,j);
            else if (j > i) b[j-1] = dist(i, j);
            else continue;
        }
        sort(b, b + 7);
        llong t1 = b[0];
        llong t2 = 2 * b[0];
        llong t3 = 3 * b[0];
        if (t1 == 0 || b[0] != t1 || b[1] != t1 || b[2] != t1 ||
            b[3] != t2 || b[4] != t2 || b[5] != t2 || b[6] != t3)
        {
            return false;
        }
        
    }
    return true;
}

// �ӵ�ǰ��i���ڵ㿪ʼ�ܹ��ҵ����ʵ�configuration
bool isOK(int i)
{
    // ������нڵ㶼�Ѿ�permutation�ã����ظø�ֵľ�����
    if (i == 8)
    {
        return check();
    }

    sort(a[i], a[i]+3);

    // ���ڵ�ǰ�ڵ��ÿһ��permutation
    do
    {
        // �����һ���ڵ㿪ʼ�����ҵ�������permutation������true
        if (isOK(i+1)) return true;

    }while(next_permutation(a[i], a[i]+3));

    return false;
}

int main()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            scanf("%I64d", &a[i][j]);
        }
    }
    
    if (isOK(0))
    {
        printf("YES\n");
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (j == 0) printf("%I64d", a[i][j]);
                else printf(" %I64d", a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
