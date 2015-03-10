#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

// ˫ָ��ǰ�󲽽���
// ��ʼrightָ��һֱ��ֱ�������ظ��ַ����������ַ���Ϊ1����������ȣ�
// ��ʱ����ȷ������ظ��Ӵ�ֻ�ܳ����ڸ��ظ��ַ���һ�γ���֮���λ�ÿ�ʼ
// �Ӷ�leftָ�벻�ϲ�����ֱ�������ظ��ַ�, ͬʱ���������ַ�ȫ����λΪ-1
int lengthOfLongestSubstring(string s)
{
	int n = s.size();

	int ans = 0;
	//unordered_map<char, int> chars;
	vector<int> visited(256, -1);
	
	int i = 0;
	int j = 0;
	while (j < n)
	{

		// ��ָ���ƶ�
		// find the first repeated char
		while (j < n && visited[s[j]] == -1)
		{
			visited[s[j]] = 1;
			j++;
		}

		if (j >= n)
		{
			ans = max(ans, j - i);
			break;
		}
		else
		{
			// ��ָ���ƶ�
			// find repeated chars
			ans = max(ans, j - i);
			
			while (s[i] != s[j])
			{
				visited[s[i]] = -1;
				i++;
			}
			i++;
			j++;
		}

	}
	return ans;
}

int main()
{
	string s;
	cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}