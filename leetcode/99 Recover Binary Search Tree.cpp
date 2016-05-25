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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* prev = NULL;
TreeNode* cur = NULL;
TreeNode* first = NULL;
TreeNode* second = NULL;
void InOrder(TreeNode* root) {
    if (root == NULL) return;
        
    InOrder(root->left);
        
    if (prev == NULL) {
        cur = prev = root;
    } else {
        cur = root;
		// �ҵ���һ���������ݶԣ�set����ָ��Ϊ������Ԫ��
        if (cur->val <= prev->val) {
            if (first == NULL) {
                first = prev;
                second = cur;
			// ����ҵ��ڶ����������ݶԣ�reset�ڶ���ָ��Ԫ��
            } else {
                second = cur;
            }
        }
        prev = cur;
    }
        
        
    InOrder(root->right);
}
    

void recoverTree(TreeNode* root) {
    if (root == NULL) return;
        
    InOrder(root);
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    } else if (first != NULL && second == NULL) {
        int temp = prev->val;
        prev->val = first->val;
        first->val = temp;
    }
        
}