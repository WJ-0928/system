#pragma once

typedef int DLDataType;
typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//ָ��ǰ�ڵ����һ���ڵ�
	struct DHCListNode* prev;//ָ��ǰ�ڵ��ǰһ���ڵ�
}Node;

Node* DHCListInit();
void DHCListPushBack(Node* head, DLDataType data);
void DHCListPopBack(Node* head);
void DHCListPushFront(Node* head, DLDataType data);
void DHCListPopFront(Node* head);

void DHCListInsert(Node* pos, DLDataType data);
void DHCListErase(Node* pos);

int DHCListSize(Node* head);
int DHCListEmpty(Node* head);
Node* DHCListFind(Node* head, DLDataType data);
void DHCClear(Node* head);
void DHCListDestroy(Node** head);

void TestDHList();
