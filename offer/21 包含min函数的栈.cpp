#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

/**
 * Ҫ����O(1)��ʱ����ʵ��ջ�� push, pop & min ����
 *
 * ����˼·��
 * ά������ջ������һ����������ջ����һ��ջ����ά�ֵ�ǰջ�ṹ����Сֵ.
 *   Push���Ƚ��½����ֵ�� min_stack����Сֵ��ջ��Ԫ�أ��������С������
 *         �½���Ԫ�أ���֮��������뵱ǰ����Сֵ��ջ��Ԫ�أ�.
 *   Pop:  ֱ��pop����ջ����.
 *   Min:  ȡ min_stack ��ջ��Ԫ��. 
 */
class StackWithMin {
public:
	void Push(int x);
	void Pop();
	int Top();
	int GetMin();
private:
	stack<int> m_data;
	stack<int> m_min;
};
void StackWithMin::Push(int x) {
	m_data.push(x);
	if (m_min.empty()) {
		m_min.push(x);
	} else {
		int curMin = m_min.top();
		if (x < curMin) {
			curMin = x;
		}
		m_min.push(curMin);
	}
}
void StackWithMin::Pop() {
	assert(!m_data.empty());
	m_data.pop();
	m_min.pop();
}
int StackWithMin::Top() {
	assert(!m_data.empty());
	return m_data.top();
}
int StackWithMin::GetMin() {
	assert(!m_data.empty());
	return m_min.top();
}

// test
int main() {
	StackWithMin s;
	s.Push(4);
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(3);
	cout << s.GetMin() << "\t Expected 3" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(5);
	cout << s.GetMin() << "\t Expected 4" << endl;
	s.Push(1);
	cout << s.GetMin() << "\t Expected 1" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	
	s.Pop();
	cout << s.GetMin() << "\t Expected 4" << endl;
	return 0;
}
