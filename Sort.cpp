#include"Sort.h"
#include<stdio.h>
#include<stack>
#include<assert.h>
#include<string.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
//��������
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
	
}

//ϣ������
void ShellSort(int* array, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap=gap/2;
		for (int i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;

			while (key < array[end] && end >= 0)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void SelectSortOp(int* array, int size)
{
	int begin = 0, end = size - 1;

	while (begin < end)
	{
		//���������������С
		int minPos = begin;
		int maxPos = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] > array[maxPos])
				maxPos = index;
			if (array[index] < array[minPos])
				minPos = index;

			++index;
		}

		//ע�⣺���Ҳ�λ�ÿ��ܴ洢���ǵ�ǰ��Сֵ
		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);//�����������һ��������
		}
		//������Ҳ��λ�ÿ��ܴ洢���ǵ�ǰ����Сֵ��������������֮��,��Сֵ��λ���Ѿ������ı�
		//����Ҫ����minPos
		if (minPos == end)
		{
			minPos = maxPos;
		}
		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);//���ڣ�a+min��a+left����С��������������ĵ�һ��������
		}
		++begin;
		--end;
	}
}
void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
			{
				maxPos = j;
			}
		}
		if (maxPos != size - 1 - i)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		//�����������ֵ������������ֵ����������Ϊ������
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* array, int size)
{
	int end = size - 1;
	//1������
	//�ҵ�������һ����Ҷ�ӽڵ�
	for(int root = ((size - 2) >> 1); root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}
	//2�����ö�ɾ����˼������������
	while (end)
	{
		Swap(&array[0], &array[end]);//�Ѷ�Ԫ�غ�������������һ��������
		HeapAdjust(array, end, 0);
		end--;
	}
}

void BubbleSort(int* array, int size)
{
	//���ѭ�����Ƶ���ð�����������������Ҫð�ݶ��ٴ�
	for (int i = 0; i < size-1; ++i)
	{
		int isChange = 0;
		//����ð�ݵķ�ʽ����������������Ԫ�ؽ��бȽϣ������Ԫ������
		//j:��ʾ������±�--->j��ʾ��һ��Ԫ�صı�־
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j-1] > array[j])
			{
				Swap(&array[j - 1], &array[j]);
				isChange = 1;
			}
		}
		//���û�б��޸ģ�˵������
		if (!isChange)
		{
			return;
		}
	}
}
int GetIndexOfmid(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

//hoare�汾
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[end];

	while (begin < end)
	{
		//��begin��ǰ�����ң��ұȻ�׼ֱ���Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[begin] <= key)
			begin++;
		//��end��ǰ��ǰ�ң��ұȻ�׼ֱС��Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}
//�ڿӷ�

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[end];

	while (begin<end)
	{
		//��begin��ǰ�����ң��ұȻ�׼ֱ���Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[begin] <= key)
			begin++;
		//��beginλ�õ�Ԫ����endλ�õĿ�
		if (begin < end)
		{
			array[end--] = array[begin];
		}

		//����beginλ���γ�һ���µĿ�
		//��end��ǰ��ǰ�ң��ұȻ�׼ֱС��Ԫ�أ��ҵ�֮��ֹͣ
		while (begin < end && array[end] >= key)
			end--;

		//end�ҵ���һ���Ȼ�׼ֵС��Ԫ��
		//��endλ�õ�Ԫ����beginλ�õĿ�
		if (begin < end)
		{
			array[begin++] = array[end];
		}
	}
	//�û�׼ֵ�����Ŀ�
	array[begin] = key;
	return begin;
}
//ǰ��ָ��汾
int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[right-1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
		{
			Swap(&array[prev], &array[cur]);
		}
		++cur;
	}
	if (++prev != right - 1)
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{
	
	if (right - left < 16)
	{
		InsertSort(array + left, right - left);
	}
	else
	{
		int div = Partion1(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}
void QuickSort(int* a, int size)
{
	QuickSort(a, 0, size);
}
//ѭ���汾��
void QuickSortNor(int* array, int size)
{
	std::stack<int> s;
	//�������������
	s.push(size);
	s.push(0);

	int left = 0, right = 0;
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();

		if (right - left > 1)
		{
			int div = Partion2(array, left, right);

			//div�ǻ�׼ֵ��λ��
			//��׼ֵ����ࣺ[left��div)
			//��׼ֵ���Ҳࣺ[div+1,right)

			s.push(right);
			s.push(div + 1);

			s.push(div);
			s.push(left);
		}
	}
}

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
}
void MergeSort(int* array, int left, int right, int* temp)
{
	//ֻ��һ��Ԫ��
	if (right - left > 1)
	{
		//�����м�λ��
		int mid = (left + ((right - left) >> 1));
		//[0,mid)[mid,size)
		MergeSort(array, left, mid, temp);
		MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);//�鲢
		memcpy(array + left, temp + left, (right - left) * sizeof(array[0]));
	}
	
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(array[0]) * size);
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	MergeSort(array, 0, size, temp);
	free(temp);
}
//ѭ����ʽ�Ĺ鲢����
void MergeSortNor(int* array, int size)
{
	int gap = 1;
	int* temp = (int*)malloc(sizeof(array[0]) * size);
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//����gap�ı仯��mid��right���ܻ�Խ��
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size*sizeof(array[0]));
		gap <<= 1;
	}
	free(temp);
}
void CountSort(int*  array, int size)
{
	//1��ͳ�����ݵķ�Χ�������Ǳ���ģ�����û��������ݷ�Χ���Ͳ���Ҫ��ͳ�Ʒ�Χ��
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	//2����������ռ�
	int range = max - min + 1;
	int* arraycount = (int*)malloc(range * sizeof(int));
	if (NULL == range)
	{
		assert(0);
		return;
	}
	memset(arraycount, 0, range * sizeof(int));
	//3��ͳ��ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < size; ++i)
	{
		arraycount[array[i] - min]++;
	}
	//4�������ݽ��л���
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (arraycount[i]--)
		{
			array[index++] = i + min;
		}
	}
	free(arraycount);
}

void TestSort()
{
	int array[] = { 4,1,7,1,3,4,6,2,6,3,2,5,8,0,9 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	/*SelectSortOp(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	SelectSort(array, sizeof(array) / sizeof(array[0]));*/
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSortNor(array, sizeof(array) / sizeof(array[0]));
	//MergeSort(array, sizeof(array) / sizeof(array[0]));
	/*MergeSortNor(array, sizeof(array) / sizeof(array[0]));*/
	CountSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}