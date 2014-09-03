#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/* 
 * ����ѹ��, ���򣬶���������
 * ����ÿ��ѧ��name����3����д��ĸ��1��������ɵģ����Ե���26������ѹ��
 * ��һ������sid, ��ÿ���γ̵ı��cidȡֵ��Χ��[1,2500]֮�䣬��������һ��
 * ��¼��ĳѧ��ѡ����ĳ�γ̿�����һ������gid = sid * 2500 + cid - 1Ψһ
 * ��ʾ��������һ��gidʱ������ͨ��gid % 2500 + 1���õ���Ӧ�Ŀγ̱�š�
 * ���ڵ���Ҫ��ѯһ��ѧ����ѡ�μ�¼ʱ�����ȼ���ѧ����sid��������ܵ�ѡ��
 * ��¼��Ȼ���������� [sid*2500, sid*2500+2499]�����Ƕ����½���ж�������
 * ���ɵõ���Ӧ��gid�������õ��γ̱��.
 * 
 * �ο���tech-wonderland.net/blog/pat-1039-course-list-for-student.html
 */

const int pow0 = 1;
const int pow1 = 26;
const int pow2 = 676;
const int pow3 = 17576;

int binarySearch(const vector<int>& gids, int gid)
{
    int n = gids.size();
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (gids[mid] == gid)
        {
            return mid;
        }
        else if (gid < gids[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int queryNum = 0;
    int courseNum = 0;
    char stuName[5];
    scanf("%d %d", &queryNum, &courseNum);

    vector<int> gids;
    gids.reserve(courseNum * 200);
    int courseID = 0; int stuCnt = 0;
    for (int k = 0; k < courseNum; ++k)
    {
        scanf("%d %d", &courseID, &stuCnt);
        for (int i = 0; i < stuCnt; ++i)
        {
            scanf("%s", stuName);
            int sid = (stuName[0] - 'A') * pow3 + 
                      (stuName[1] - 'A') * pow2 + 
                      (stuName[2] - 'A') * pow1 + 
                      (stuName[3] - '0');
            int gid = sid * 2500 + courseID - 1;
            gids.push_back(gid);
        }
    }

    sort(gids.begin(), gids.end());

    for (int k = 0; k < queryNum; ++k)
    {
        scanf("%s", stuName);
        int queryid = (stuName[0] - 'A') * pow3 + 
                      (stuName[1] - 'A') * pow2 + 
                      (stuName[2] - 'A') * pow1 + 
                      (stuName[3] - '0');
        int lowid = queryid * 2500 + 0;
        int highid = queryid * 2500 + 2499;
        int i = binarySearch(gids, lowid);
        int j = binarySearch(gids, highid);
        vector<int> ans;
        for (int kk = i; kk <= j; ++kk)
        {
            if (gids[kk] >= lowid && gids[kk] <= highid)
            {
                ans.push_back(gids[kk]);
            }
        }
        printf("%s", stuName);
        int ansNum = ans.size();
        printf(" %d", ansNum);
        for (size_t ii = 0; ii < ans.size(); ++ii)
        {
            int gid = ans[ii];
            int cid = gid % 2500 + 1;
            printf(" %d", cid);
        }
        printf("\n");
    }
    return 0;
}
