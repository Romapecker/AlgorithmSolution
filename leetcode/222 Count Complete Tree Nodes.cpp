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
#include <assert.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
        
    int lh = 0;
    int rh = 0;
	// �����������߶�
    TreeNode* pl = root->left;
    while (pl) {
        lh++;
        pl = pl->left;
    }
    
	// �����������߶�
    TreeNode* pr = root->right;
    while (pr) {
        rh++;
        pr = pr->left;
    }
    
	// ���������߶���ͬ��˵����������һ��������������ڵ���Ϊ2^lh-1���ټ���1�����ڵ�Ϊ2^lh
    if (lh == rh) {
        return (1 << lh) + countNodes(root->right);
    } else { // ����˵���������Ǳ��������߶���1���������������ϸ��ڵ��ܹ���2^rh���ڵ�
        return (1 << rh) + countNodes(root->left);
    }
}