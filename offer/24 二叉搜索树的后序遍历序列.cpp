#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * ���⣺�ж�һ�������Ƿ���BST�ĺ�����������
 * ����˼·: BST�����������������½ṹ, |small elems| large elems | root|
 * ֻҪ�����ܵݹ�ı������½ṹ����˵����BST�ĺ����������. 
 */
bool IsPostOrderOfBST(const vector<int>& A) {
	// base case: NULL array or have only one value
	if (A.size() <= 1) return true;
	
	int n = (int) A.size();
	int elem = A[n-1];
	int i = 0;
	vector<int> left;
	vector<int> right;
	// ���Ͻ�С��elem��Ԫ�������������� 
	while (i < n-1 && A[i] < elem) {
		left.push_back(A[i]);
		i++;
	}
	
	// ��һ��ѭ���˳������������i >= n-1�� ���ѭ������ִ�У�rightΪ��
	// A[i] > elem, ��ʱ���Ͻ����ڵ�Ԫ�ط����������� 
	while (i < n-1 && A[i] > elem) {
		right.push_back(A[i]);
		i++;
	}
	
	// ��Ԫ��ȫ�������꣬�����������鶼��BST
	return i == n-1 && IsPostOrderOfBST(left) && IsPostOrderOfBST(right); 
}

// test
int main() {
	int a[] = {1, 3, 2};
	int b[] = {1, 2, 3};
	int c[] = {2, 1, 3};
	int d[] = {2, 3, 1};
	int e[] = {3, 1, 2};
	int f[] = {3, 2, 1};
	int g[] = {5, 7, 6, 9, 11, 10, 8};
	int h[] = {7, 4, 6, 5};
	vector<int> A(a, a+3);
	vector<int> B(b, b+3);
	vector<int> C(c, c+3);
	vector<int> D(d, d+3);
	vector<int> E(e, e+3);
	vector<int> F(f, f+3);
	vector<int> G(g, g+7);
	vector<int> H(h, h+4);
	cout << IsPostOrderOfBST(A) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(B) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(C) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(D) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(E) << "\t Expected False" << endl;
	cout << IsPostOrderOfBST(F) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(G) << "\t Expected True" << endl;
	cout << IsPostOrderOfBST(H) << "\t Expected False" << endl;
	
	return 0;
}
