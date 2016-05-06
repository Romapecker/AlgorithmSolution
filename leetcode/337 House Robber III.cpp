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

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
// �ⷨһ���ݹ�+��ϣ�� 
//
// �������������ͨ���ݹ�ķ�ʽ���
//           a
//         b    c
//      c    d e  f
//    g   h
// �������������������Է��ֶ��ڽڵ�a��ֻ������ѡ�������߲���
// 1. ���������b, c�ڵ��Ȼ���ܱ�������ת��Ϊ���c, d, e, f�ĸ��������ٵ��ۺ�
// 2. �����������ת��Ϊb,c�������������ٵ��ۺ�
// ���ȡ���ߵĽϴ�ֵ����
int rob_recursion(TreeNode* root, unordered_map<TreeNode*, int>& hashtable) {
	if (hashtable.find(root) != hashtable.end()) {
		return hashtable[root];
	}

	if (root == NULL) {
		hashtable[root] = 0;
		return 0;
	}

	// 1. �����ڵ�
	int ans1 = root->val;
	if (root->left != NULL) ans1 += rob_recursion(root->left->left, hashtable) + rob_recursion(root->left->right, hashtable);
	if (root->right != NULL) ans1 += rob_recursion(root->right->left, hashtable) + rob_recursion(root->right->right, hashtable);

	// 2. �������ڵ�
	int ans2 = rob_recursion(root->left, hashtable) + rob_recursion(root->right, hashtable);

	hashtable[root] = max(ans1, ans2);
	return max(ans1, ans2);
}

int rob(TreeNode* root) {
	unordered_map<TreeNode*, int> hashtable;
	return rob_recursion(root, hashtable);
}
#endif //0

// �ⷨ��:
// �������������ص��������ԭ�����ڣ�û�м�¼ÿ���ڵ��Ƿ�������Ϣ
// 
// root ������ʱ�����firstԪ����
// root ����ʱ�����secondԪ����
pair<int, int> rob_recursion(TreeNode* root) {
	if (root == NULL) return make_pair(0, 0);

	pair<int, int> left_ans = rob_recursion(root->left);
	pair<int, int> right_ans = rob_recursion(root->right);

	pair<int, int> root_ans = make_pair(0, 0);
	root_ans.second = root->val + left_ans.first + right_ans.first;
	root_ans.first = max(left_ans.first, left_ans.second) + max(right_ans.first, right_ans.second);

	return root_ans;
}

int rob(TreeNode* root) {
	pair<int, int> ans = rob_recursion(root);
	return max(ans.first, ans.second);
}

