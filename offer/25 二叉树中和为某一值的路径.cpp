#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) : val(x), left(NULL), right(NULL) {
	}
};

void PrintPath(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

/**
 * ���⣺��ӡ��������·����
 * ����˼·������ǰ�ڵ�push��·�����ۼ���cursum�������ǰ�ڵ�ΪҶ�ӽڵ���
 * cursum==sum����˵��������������ӡ·��������ݹ�ĵ������������󣬻��� 
 */ 
void FindPathWithSum(Node* root, int sum, vector<int>& path, int cursum) {
	if (root == NULL) return;
	
	// base case
	if (root->left == NULL && root->right == NULL && cursum + root->val == sum) {
		path.push_back(root->val);
		PrintPath(path);
		path.pop_back();
		return;
	}
	
	path.push_back(root->val);
	cursum += root->val;
	FindPathWithSum(root->left, sum, path, cursum);
	FindPathWithSum(root->right, sum, path, cursum);
	path.pop_back();	
}

// test
int main() {
	Node* root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(12);
	root->left->left = new Node(4);
	root->left->right = new Node(7);
	
	vector<int> path;
	FindPathWithSum(root, 22, path, 0);
	return 0; 
}
