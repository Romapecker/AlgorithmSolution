#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



// List n || ����ʤ1��ʾ������ʤ0��ʾ
//      1 || 1
//      2 || 1
//      3 || 1
//      4 || 0
//      5 || 1
//      6 || 1
//      7 || 1
//      8 || 0
// ���赱ǰ��n��ʯ�ӣ�������3��ѡ��
// ѡ��1����2����3����ʣ��n-1, n-2, n-3��ʯ��
// ���ʣ���n-1, n-2, n-3�д��ں��ֵı�ʤ�Ĳ���
// ���������Ȼ��ʤ��
// ���仰˵�����֮ǰ�������д���0����ǰn����ʤ����
// �����Ļ������Դ���ͼ��������ʵ����4�ı�����Ȼ�䣬��֮��ʤ
bool canWinNim(int n) {
	return n % 4 != 0;
}

int main()
{
	cout << canWinNim(1348820612) << endl;
	return 0;
}