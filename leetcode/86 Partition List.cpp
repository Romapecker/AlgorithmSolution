#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <assert.h>
#include <stdio.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ����һ������quicksort��partition˼��
ListNode* partition(ListNode* head, int x) {
	if (head == NULL) return NULL;

	ListNode* pi = NULL;

	ListNode* pj = head;
	ListNode* pj_prev = NULL;
	for (pj = head; pj != NULL; ) {
		if (pj->val >= x) {
			pj_prev = pj;
			pj = pj->next;
		} else {
			// ɾ��pj��ָ�Ľڵ�
			ListNode* temp = pj;
			if (pj_prev == NULL) {
				head->next = temp->next;
			} else {
				pj_prev->next = temp->next;
			}
			pj = temp->next;

			// ����ýڵ㵽pi�ĺ���
			if (pi == NULL) {
				temp->next = head;
				head = pi = temp;
			} else {
				temp->next = pi->next;
				pi->next = temp;
			}
		}
	}
	return head;
}

// ��������ά����������һ��С�ڣ�һ�����ڵ���x�����
// ����������������
ListNode* partition(ListNode* head, int x) {
	ListNode* node1 = new ListNode(0);
	ListNode* node2 = new ListNode(0);
	ListNode* p1 = node1;
	ListNode* p2 = node2;
	while (head) {
		if (head->val < x) {
			p1->next = head;
			p1 = p1->next;
		} else {
			p2->next = head;
			p2 = p2->next;
		}
		head = head->next;
	}
	p2->next = NULL;
	p1->next = node2->next;
	return node1->next;
}