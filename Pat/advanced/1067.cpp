#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

// ����v[0]!= 0ʱ��ѭ�����ȣ���ֵ�ϵ��ڽ�������
int cntSwap(vector<int>& v)
{
    int ans = 0;
    while (v[0] != 0)
    {
        int x = v[0];
        swap(v[0], v[x]);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) // ����ÿһ�����֣��ж��Ƿ��λ
    {
        if (v[i] != i)          // �����������δ��Ϊ
        {
            if (v[0] == 0)      // ��һ���ж�v[0]�Ƿ����0���������0
                                // ��Ҫ���Ⱥ�v[0] swap һ��
            {
                swap(v[0], v[i]);
                cnt++;
            }

            cnt += cntSwap(v);  // Ȼ�����ѭ���ĳ���
        }
    }

    printf("%d\n", cnt);
    return 0;
}

/*
 * ����
 * 1. ���v[0] != 0, ��v[0] = x, v[x] = y, v[y] = z, ..., v[z] = 0��
 *    swap�Ĵ������ڸ�ѭ�����ĳ���
 * 2. ���v[0] == 0, ��������v[i]!=i��������˵��swap�Ĺ����в�����0�Ĳ��룬
 *    Ϊ�˱�֤swap(0, *)����Ҫ����swap(v[0], v[i])һ�Σ�Ȼ��ת��Ϊ1�����
 * �ο���
 * tech-wonderland.net/blog/pat-1067-sort-with-swap-zero.html
 */
