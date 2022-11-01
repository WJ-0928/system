#include "Seqlist.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
//��ʼ��
void  SeqListInit(Seqlist* s, int initcapacity)
{
	assert(s);
	initcapacity = initcapacity <= 3 ? 3 : initcapacity;
	s->array = (SDataType*)malloc(sizeof(SDataType*) * initcapacity);
	if (NULL == s->array)
		return;

	s->capacity = initcapacity;
	s->size = 0;
}
//����
// 1�������¿ռ�
// 2������Ԫ��
// 3���ͷžɿռ�
// 4��ʹ���¿ռ�
int CheckCapacity(Seqlist* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array, newCapacity * sizeof(SDataType));
		if (NULL == s->array)
			return 0;

		s->capacity = newCapacity;
		////�����¿ռ�
		//SDataType* temp = (SDataType*)malloc(newCapacity * sizeof(SDataType));
		////����Ԫ��
		//memcpy(temp, s->array, s->capacity * sizeof(SDataType));
		////�ͷžɿռ�
		//free(s->array);
		////ʹ���¿ռ�
		//s->array = temp;
		//s->capacity = newCapacity;
	}
	return 1;
}

//β��
//1������Ҫ���ݣ�ֱ�ӽ�Ԫ�ز���sizeλ��
//2����Ҫ����
void SeqListPushBack(Seqlist* s, SDataType data)
{
	assert(s);
	//�ڲ���֮ǰҪ��֤�пռ�
	if (!CheckCapacity(s))
		return;

	s->array[s->size++] =data;
}
//βɾ
void SeqListPopBack(Seqlist* s)
{
	assert(s);
	if (SeqListEmpty(s))
		return;
	s->size--;
}
//�ײ�
//1���ȼ���Ƿ���Ҫ����--�����Ҫ������
//2����˳���������Ԫ�������������һ��λ��
//3����data���뵽˳������ʼλ��
void SeqListPushFront(Seqlist* s, SDataType data)
{
	if (!CheckCapacity(s))
		return;

	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->size++;
}

//��ɾ--����һ��Ԫ���⣬ʣ��Ԫ��������ǰ����
void SeqListPopFront(Seqlist* s)
{
	if (SeqListEmpty(s))
		return;
	for (int i = 1; i < s->size; ++i)
	{
		s->array[i - 1] = s->array[i];
	}
	s->size--;
}
//����λ�ò���
//1��pos�ķ�Χ��[0��size]
//2������Ƿ���Ҫ����
//3����[pos��size)λ�õ�Ԫ�������������һ��λ��
//4����pos��λ�ò�����Ԫ��
void SeqListInsert(Seqlist* s, int pos, SDataType data)
{
	assert(s);
	if (pos<0 || pos>s->size)
		return;
	if (!CheckCapacity(s))
		return;
	for (int i = s->size - 1; i >= pos; --i)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = data;
	s->size++;
}
//����λ��ɾ��
//1��pos������[0��size��
//2����pos֮�������Ԫ��������ǰ����һ��λ��
void SeqListErase(Seqlist* s, int pos)
{
	assert(s);
	if (pos < 0 || pos >= s->size)
		return;

	for (int i = pos + 1; i < s->size; ++i)
		s->array[i-1] = s->array[i];
	
	s->size--;
}
//��ȡ˳�������ЧԪ�ظ���
int SeqListSize(Seqlist* s)
{
	assert(s);
	return s->size;
}
//��ȡ˳��������
int SeqListCapacity(Seqlist* s)
{
	assert(s);
	return s->capacity;
}
//���˳����Ƿ�Ϊ��
int SeqListEmpty(Seqlist* s)
{
	assert(s);
	return 0 == s->size;
}
//����data�Ƿ���˳�����
int SeqListFind(Seqlist* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
	{
		if (data == s->array[i])
		{
			return i;
		}
	}
	return -1;
}
//���
void SeqListClear(Seqlist* s)
{
	assert(s);
	s->size = 0;
}
//����
void SeqListDestroy(Seqlist* s)
{
	assert(s);
	if (s->array)
	{
		free(s->array);
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}

//��ӡ
void SeqListPrint(Seqlist* s)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
	{
		printf("%d", s->array[i]);
	}
	printf("\n");
}
void Test1()
{
	Seqlist s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);


	SeqListDestroy(&s);
}
void Test2()
{
	Seqlist s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	//����λ�ò���
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);
	//ɾ����һ��Ԫ��4
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}
void TestSeqList()
{
	//Test1();
	Test2();
}