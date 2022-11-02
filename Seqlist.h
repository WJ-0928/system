#pragma once

typedef int SDataType;
typedef struct Seqlist
{
	SDataType* array;//���Ԫ�صĿռ䣬������ʱ��������
	SDataType capacity;//�ռ��ܵô�С
	SDataType size;  //�ռ�����ЧԪ�ظ���
}Seqlist;
//typedef struct Seqlist Seqlist;
	
void  SeqListInit(Seqlist* s, int initcapacity);
//β��
void SeqListPushBack(Seqlist* s, SDataType data);
//βɾ
void SeqListPopBack(Seqlist* s);
//�ײ�
void SeqListPushFront(Seqlist* s, SDataType data);
//��ɾ
void SeqListPopFront(Seqlist* s);
//����λ�ò���
void SeqListInsert(Seqlist* s, int pos, SDataType data);
//����λ��ɾ��
void SeqListErase(Seqlist* s, int pos);
//��ȡ˳�������ЧԪ�ظ���
int SeqListSize(Seqlist* s);
//��ȡ˳��������
int SeqListCapacity(Seqlist* s);
//���˳����Ƿ�Ϊ��
int SeqListEmpty(Seqlist* s);
//����data�Ƿ���˳�����
int SeqListFind(Seqlist* s, SDataType data);
//���
void SeqListClear(Seqlist* s);
//����
void SeqListDestroy(Seqlist* s);

//����
void TestSeqList();