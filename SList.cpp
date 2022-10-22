#include "SList.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
//����ڵ�
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
/*
ע��:
�����Ҫ�ں����иı�ͷָ���ָ���βα���Ϊ����ָ��
�������Ҫ�ں����иı�ͷָ���ָ��ֻ�贫��һ��ֱ�߼��ɣ�����:SListFind
*/
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);//��������
	//����Ϊ��
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
		//newNode->next = NULL;
	}
}

void SListPopBack(SListNode** head)
{
	assert(head);//���Ƿ����
	if (NULL == *head)
	{
		return;
	}
	else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		SListNode* cur = *head;
		SListNode* prev = NULL;//���cur��ǰһ���ڵ�
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);	
	}
}
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	newNode->next = *head;
	*head = newNode;
	/*if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		*head = newNode;
	}*/
}
void SListPopFront(SListNode** head)
{
	assert(head);
	if (NULL == *head)
	{
		return;
	}
	SListNode* del = *head;
	*head = del->next;
	free(del);

	/*else if (NULL == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		SListNode* del = *head;
		*head = del->next;
		free(del);
	}*/
}

void SListInsertAfter(SListNode* pos, SLDataType data)
{
	if (NULL == pos)
	{
		return;
	}
	SListNode* newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListErase(SListNode* pos)
{
	if (NULL == pos || NULL == pos->next)
		return;
	SListNode* del = pos->next;
	pos->next = del->next;
	free(del);
}

int SListSize(SListNode* head)
{
	SListNode* cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int SListEmpty(SListNode* head)
{
	return NULL == head;
}

SListNode* SListFind(SListNode* head, SLDataType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListDestroy(SListNode** head)
{
	assert(head);
	while (*head)
	{
		SListNode* del = *head;
		*head = del->next;
		free(del);
	}
}
void PrintSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void TestSList()
{
	SListNode* head = NULL;
	/*SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);

	SListPopBack(&head);
	SListPopBack(&head)
	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPushFront(&head, 5);;*/
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);
	SListInsertAfter(SListFind(head, 3), 0);
	SListInsertAfter(SListFind(head, 100), 10);
	SListErase(SListFind(head,5));
	SListErase(SListFind(head, 2));
	PrintSList(head);
	SListDestroy(&head);
}
