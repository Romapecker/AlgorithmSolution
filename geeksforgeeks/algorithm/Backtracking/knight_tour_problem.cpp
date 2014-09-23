/*
 * Backtracking ������һ��ͨ�õ��㷨˼�룬���������п��ܵ�solution��ֱ��
 * �ҵ�һ��solution.
 *
 * �����ڻ����㷨������һ��������������
 * ���������ͨ���������п��ܵ�configuration�������Naive���㷨ͨ������
 * ���е�configuration�ж��Ƿ������������Ӷ��������.
 * ���ݵ��㷨��ͨ��һ�������ķ�ʽ�����Բ�ͬ��configuration��һ����˵
 * ����ͨ��һ���յ�solution��ÿһ�����һ��item(item������������Ĳ�ͬ
 * ����ͬ��. ����������һ��item��ʱ�������ж����ӵ�item�Ƿ��ƻ�������
 * ��Լ�������� ����ǣ����������remove���item������һ��item���ӡ�
 * ������ǣ����ǵݹ������items one byone��ֱ�������ҵ�solution������
 * �����Ҳ���.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 8;
int dx[N] = {2, 1, -2, -1, -2, -1,  2,  1};
int dy[N] = {1, 2,  1,  2, -1, -2, -1, -2};

void PrintSolution(int sol[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool isSafe(int x, int y, int sol[N][N])
{
    if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
    {
        return true; 
    }
    
    return false;
}

// ��ǰ��curx, curyλ�ã���һ��������curCnt, �ܹ�lead to a solution
bool solveUtil(int curx, int cury, int curCnt, int sol[N][N])
{
    if (curCnt == N * N)
    {
        return true;
    }

    for (int i = 0; i < N; ++i)
    {
        // ��������һ��
        int nextx = curx + dx[i];
        int nexty = cury + dy[i];

        if (isSafe(nextx, nexty, sol))
        {
            //��������ǰ�ȫ�ģ���ֵ
            sol[nextx][nexty] = curCnt;

            if (solveUtil(nextx, nexty, curCnt+1, sol))
            {
                return true;
            }

            // ����
            sol[nextx][nexty] = -1;
        }
    }

    return false;
}

bool SolveKT()
{
    int sol[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            sol[i][j] = -1;
        }
    }

    sol[0][0] = 0;
    if (solveUtil(0, 0, 1, sol))
    {
        PrintSolution(sol);
        return false;
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }

    return true;
}

int main()
{
    SolveKT();
    cout << "hello" << endl;
    return 0;
}
