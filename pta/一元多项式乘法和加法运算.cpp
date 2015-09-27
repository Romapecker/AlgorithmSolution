#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct ListNode
{
	int coef;
	int expn;
	ListNode* next;
	
	// ����û�г�ʼ�� next ��ָ��������ϵͳ���������ǣ�
	ListNode(int _coef, int _expn) : coef(_coef), expn(_expn), next(NULL) {}
};

/* ׷��һ�ԭ�еĶ���ʽ��� */
void AttachNode(ListNode* &head, ListNode* &last, int coef, int expn)
{
	if (last == NULL) {
		head = last = new ListNode(coef, expn);
	} else {
		last->next = new ListNode(coef, expn);
		last = last->next;
	}
}

/* ������������ʽ�˻��������µĶ���ʽ��Ϊ��� */
ListNode* MultiPoly(ListNode* L1, ListNode* L2)
{
	if (L1 == NULL || L2 == NULL) return NULL;
	
	ListNode* p1 = L1;
	ListNode* p2 = L2;
	ListNode* head = NULL;
	ListNode* last = NULL;
	
	// L1����ʽ�ĵ�һ����L2�ĸ�����ˣ������ʼ����Ķ���ʽ
	while (p2 != NULL) {
		int c = p1->coef * p2->coef;
		int e = p1->expn + p2->expn;
		if (c != 0) {
			AttachNode(head, last, c, e);
		}
		p2 = p2->next;
	}
	
	p1 = p1->next;
	while (p1 != NULL) {
		// ����L1��һ����L2ÿһ��˻��Ľ��
		for (p2 = L2; p2 != NULL; p2 = p2->next) {
			int c = p1->coef * p2->coef;
			int e = p1->expn + p2->expn;
			
			// �ڽ������ʽ��Ѱ�Һ��ʵ�λ�ý��в�����ߺϲ�
			ListNode* pre = NULL;
			ListNode* cur = head;
			while (cur != NULL && cur->expn > e) {
				pre = cur;
				cur = cur->next;
			}
			// ����ָ�����ȵ�ǰ��Ҫ��ֱ�Ӳ嵽�����
			if (cur == NULL) {
				ListNode* newNode = new ListNode(c, e);
				if (pre == NULL) head = newNode;
				else pre->next = newNode;
			} else {
				// �ҵ�ָ����ȵģ���Ҫ�ϲ�
				if (cur->expn == e) {
					cur->coef += c;
					// �ϲ���ָ���պ�Ϊ0����Ҫɾ������
					if (cur->coef == 0) {
						ListNode* tmp = cur;
						if (pre == NULL) head = head->next;
						else pre = pre->next;
						delete tmp;
					}
				} else if (cur->expn < e) { // �ҵ�ָ������С�ģ���Ҫ���뵽����
					ListNode* newNode = new ListNode(c, e);
					if (pre == NULL) {
						newNode->next = head;
						head = newNode;
					} else {
						newNode->next = pre->next;
						pre->next = newNode;
					}
				}
			}
		}
		p1 = p1->next;
	}
	return head;
}


/* ������������ʽ�ĺͣ������µĶ���ʽ��Ϊ��� */
ListNode* AddPoly(ListNode* L1, ListNode* L2)
{
	ListNode* p1 = L1;
	ListNode* p2 = L2;
	ListNode* head = NULL;
	ListNode* last = NULL;
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->expn == p2->expn) {
			if (p1->coef + p2->coef != 0) {
				AttachNode(head, last, p1->coef + p2->coef, p1->expn);
			}
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->expn > p2->expn) {
			if (p1->coef != 0) {
				AttachNode(head, last, p1->coef, p1->expn);
			}
			p1 = p1->next;
		} else {
			if (p2->coef != 0) {
				AttachNode(head, last, p2->coef, p2->expn);
			}
			p2 = p2->next;
		}
	}
	
	while (p1 != NULL) {
		AttachNode(head, last, p1->coef, p1->expn);
		p1 = p1->next;
	}
	
	while (p2 != NULL) {
		AttachNode(head, last, p2->coef, p2->expn);
		p2 = p2->next;
	}
	
	return head;
}


void PrintPoly(ListNode* L)
{
	if (L == NULL) {
		cout << "0 0" << endl;
		return;
	}
	
	bool isFirst = true;
	for (ListNode* p = L; p != NULL; p = p->next) {
		if (isFirst) {
			isFirst = false;
			cout << p->coef << " " << p->expn;
		} else {
			cout << " " << p->coef << " " << p->expn;
		}
		
	}
	cout << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n1, n2;
	int coef, expn;
	ListNode* head1 = NULL; ListNode* last1 = NULL;
	ListNode* head2 = NULL; ListNode* last2 = NULL;
	cin >> n1;
	for (int i = 0; i < n1; ++i) {
		cin >> coef >> expn;
		AttachNode(head1, last1, coef, expn);
	}
	cin >> n2;
	for (int i = 0; i < n2; ++i) {
		cin >> coef >> expn;
		AttachNode(head2, last2, coef, expn);
	}
	
	ListNode* ans1 = MultiPoly(head1, head2);
	PrintPoly(ans1);
	ListNode* ans2 = AddPoly(head1, head2);
	PrintPoly(ans2);
	return 0;
}
