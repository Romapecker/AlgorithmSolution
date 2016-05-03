#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * ��׼�˷�����
 * ע���λ���ļ��㣬��leading zeros���Ƴ�����
 */
string multiply(string num1, string num2) {
	int n1 = (int)num1.size();
	int n2 = (int)num2.size();
	string ans(n1+n2, '0');
	int k = n1 + n2 - 1;

	int i = n1 - 1;
	int j = n2 - 1;
	int carry = 0;

	for (j = n2 - 1; j >= 0; --j) {
		k = j + n1;
		carry = 0; // �����λ��
		for (i = n1 - 1; i >= 0; --i) {
			int curNum = (num2[j] - '0') * (num1[i] - '0');
			curNum += (ans[k] - '0') + carry;
			ans[k] = (curNum % 10) + '0';
			carry = curNum / 10;
			k--;
		}

		// �����λ��������0,�򽫽�λ������ǰ��
		while (carry != 0) {
			ans[k--] = (carry % 10) + '0';
			carry /= 10;
		}
	}

	// �Ƴ�leading zeros
	size_t pos = ans.find_first_not_of('0');
	if (pos != string::npos) {
		ans = ans.substr(pos);
	} else { // �����ȫ0
		ans = "0";
	}

	return ans;

}

#if 0
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << multiply(s1, s2) << endl;
	return 0;
}
#endif //0