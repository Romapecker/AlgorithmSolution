#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ListNode
{
	int address;
	int value;
	ListNode* next;
	// constructor
	ListNode(int _add, int _value) : address(_add), value(_value), next(NULL) {}
};

pair<int, int> A[100000];

int main()
{
	//freopen("input.txt", "r", stdin);
	int firstAdd, N, K;
	int curAdd, value, nextAdd;
	scanf("%d %d %d", &firstAdd, &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d %d", &curAdd, &value, &nextAdd);
		A[curAdd].first = value;
		A[curAdd].second = nextAdd;
	}
	
	// Ϊ����߽������Ĵ������ô�һ��ͷ�ڵ��������Ϊ������
	// ����������Ϣ������ʼ����
	ListNode* head = new ListNode(-1111, -1111);
	ListNode* last = head;
	curAdd = firstAdd;
	while (curAdd != -1) {
		last->next = new ListNode(curAdd, A[curAdd].first);
		last = last->next;
		curAdd = A[curAdd].second;
	}
	
	ListNode* preFirst = head;
	ListNode* first = head->next;
	ListNode* pre = head;
	ListNode* cur = head->next;
	int cnt = 0;
	while (true) {
		// Ѱ��K���ڵ�����䣬����ҵ����������з�ת
        // �����Ҳ���K���ڵ㣬��ת��ֹ
		while (cur != NULL) {
			cnt++;
			if (cnt == K) break;
			cur = cur->next;
		}
		
		if (cnt != K) {
			break;
		} else {
			ListNode* last = cur;
			ListNode* lastNext = cur->next;
			
			//��תK���ڵ�
			pre = preFirst;
			cur = first;
			while (cur != lastNext) {
				ListNode* curNext = cur->next;
				if (cur == first) {
					cur->next = lastNext;
				} else {
					cur->next = pre;
				}
				pre = cur;
				cur = curNext;
			}
			preFirst->next = last;
			
			// ���³�ʼ��Ϣ
			preFirst = first;
			first = lastNext;
			cnt = 0;
		}
	}
	
	// �������
	for (ListNode* p = head->next; p != NULL; p = p->next) {
		printf("%05d %d", p->address, p->value);
		if (p->next != NULL) printf(" %05d\n", p->next->address);
		else printf(" -1\n");
	}
	
	return 0;
}
