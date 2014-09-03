#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

// ���һ��sample�����ڴ棬��Ҫԭ������Ϊ����/�γ̱�ռ���ڴ�̫��
// ����ģ���Ҫѹ��ѧ��������γ����ƣ�AC�����1039_2.cpp
int main()
{
    freopen("input.txt", "r", stdin);

    char stuName[5];
    long queryNumber = 0;
    int courseNumber = 0;
    //cin >> queryNumber >> courseNumber;
    scanf("%ld %d", &queryNumber, &courseNumber); 

    map<string, set<int> > table;
    int courseIndex = 0;
    long studentNumber = 0;
    //string name;
    for (int i = 0; i < courseNumber; ++i)
    {
        //cin >> courseIndex >> studentNumber;
        scanf("%d %ld", &courseIndex, &studentNumber);
        for (int k = 0; k < studentNumber; ++k)
        {
            //cin >> name;
            scanf("%s", stuName);
            string name(stuName);
            table[name].insert(courseIndex);
        }
    }

    vector<string> querylist(queryNumber);
    for (long i = 0; i < queryNumber; ++i)
    {
        //cin >> queryName;
        scanf("%s", stuName);
        string queryName(stuName);
        int registerNumber = table[queryName].size();
        //cout << queryName << " " << registerNumber;
        printf("%s %d", stuName, registerNumber);
        if (registerNumber == 0)
        {
            //cout << endl;
            printf("\n");
        }
        else
        {
            for (auto it = table[queryName].begin(); 
                      it != table[queryName].end(); ++it)
            {
                //cout << " " << *it;
                printf(" %d", *it);
            }
            //cout << endl;
            printf("\n");
        }
    }

    return 0;
}
