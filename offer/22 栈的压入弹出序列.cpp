#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

/**
 * ���⣺�жϳ�ջ�����Ƿ�Ϸ�
 * ����˼·����һ��ջ��ģ�⣬������վ����push�����ݳ�ջ����pop
 * �������������ջ��Ԫ�ظպõ��ڳ�ջԪ�أ���ôֱ�ӳ�ջ�������Ƶ���һ������ջԪ��
 * ���򣬲��ϵİ�����ջ����push��ֱ����������ջԪ�أ����ֱ�����пն�û���ҵ�����ô
 * ���зǷ������򽫴���ջԪ��Ҳpush��ջ�� 
 */
bool IsPopOrder(const vector<int>& push_order, const vector<int>& pop_order) {
	assert(push_order.size() == pop_order.size());
	
	int n = (int)push_order.size();
	int i = 0;
	int j = 0;
	
	stack<int> s;
	while (j < n) {
		int pop_elem = pop_order[j];
		if (!s.empty() && s.top() == pop_elem) {
			s.pop(); // ��ջ���ҵ�����Ҫpop��Ԫ�أ�ֱ��pop��ȥ 
			j++;     // ��ѯ��һ����Ҫpop��Ԫ�� 
		} else {
			// ջ��û���ҵ���Ҫpop��Ԫ��
			// ���ϵĽ�����Ԫ��push��ջ��ֱ������Ҫpop��Ԫ�� 
			while (i < n && push_order[i] != pop_elem) {
				int push_elem = push_order[i];
				s.push(push_elem);
				i++;
			}
			
			// ֱ����ջ���п�Ҳû���ҵ���Ҫpop��Ԫ�أ����зǷ� 
			if (i >= n) {
				return false;
			} else { // �ҵ���Ҫpop��Ԫ�أ���popԪ�ؽ�ջ 
				assert(push_order[i] == pop_elem);
				s.push(push_order[i]);
				i++;
			}
		}
	}
	
	return s.empty() && j >= n;
}

// test
int main() {
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {4, 5, 3, 2, 1};
	int c[] = {4, 3, 5, 1, 2};
	int d[] = {1, 2, 3, 4, 5};
	int e[] = {5, 4, 3, 2, 1};
	int f[] = {1, 3, 2, 4, 5};
	int g[] = {1, 3, 2, 5, 4};
	vector<int> A(a, a+5);
	vector<int> B(b, b+5);
	vector<int> C(c, c+5);
	vector<int> D(d, d+5);
	vector<int> E(e, e+5);
	vector<int> F(f, f+5);
	vector<int> G(g, g+5);
	cout << IsPopOrder(A, B) << " \t Expected true" << endl;
	cout << IsPopOrder(A, C) << " \t Expected false" << endl;
	cout << IsPopOrder(A, D) << " \t Expected true" << endl;
	cout << IsPopOrder(A, E) << " \t Expected true" << endl;
	cout << IsPopOrder(A, F) << " \t Expected true" << endl;
	cout << IsPopOrder(A, G) << " \t Expected true" << endl;

	int h[] = {1};
	int i[] = {1};
	int j[] = {2};
	vector<int> H(h, h+1);
	vector<int> I(i, i+1);
	vector<int> J(j, j+1);
	
	cout << IsPopOrder(H, I) << " \t Expected True" << endl;
	cout << IsPopOrder(H, J) << " \t Expected false" << endl;
	
	return 0;
}
