#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

/* �����������⣬��Ҫʹ��С�������ݽṹ
 * ���ȼ�����Ĭ���Ǵ���ѣ�ͨ���ı�Ƚ������greater<int>��Ϊ
 * С����ʹ��
 *  
 *  ��סpriority_queue��ģ�������Ҫָ��
 *  priority_queue<int, vector<int>, greater<int> > q;
 */
int main()
{
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        q.push(x);
    }

    int cost = 0;
    int x1, x2;
    while (q.size() >= 2)
    {
        x1 = q.top();
        q.pop();
        x2 = q.top();
        q.pop();
        cost += x1 + x2;
        q.push(x1 + x2);
    }

    cout << cost << endl;
    return 0;
}
