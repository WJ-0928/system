#pragma once

typedef int SDataType;


/*
��̬ջ��
#define MAXSIZE 100
typedef struct Stack
{
	SDataType array[MAXSIZE];
	int top;
}Stack;

����ڱ�����Ҫ�õ�ջ���Լ����Կ��ٶ���һ����̬ջ������������
*/
typedef struct Stack
{
	SDataType* array;
	int capacity;
	int size;//ջ��Ԫ�ظ���
}Stack;

void StackInit(Stack* ps);
//��ջ��β��
void StackPush(Stack* ps, SDataType data);
//��ջ��βɾ
void StackPop(Stack* ps);
//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
//����
void StackDestroy(Stack* ps);
void TestStack();