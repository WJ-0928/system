//#include<iostream>
//using namespace std;

//int main()
//{
//	int array[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	cout << &array << endl;
//	cout << &array + 1 << endl;
//
//	cout << array << endl;
//	cout << array + 1 << endl;
//
//	cout << &array[0] << endl;
//	cout << (&array[0]) + 1 << endl;
//
//	return 0;
//}


//C++ΪʲôҪ��һ�׶�̬�ڴ����
//���ȣ�C�����еĶ�̬�ڴ����ʽ��C++����Ȼ����ʹ��
//ԭ��1��C�����еķ�ʽ�Ƚ��鷳---��Ҫ�û��ֶ����ֽ�������Ҫ�Է��ؽ��ǿת����Ҫ�пգ���Ҫ����ͷ�ļ�
//		2��malloc��free:������ù��캯��/����������new��delete���ڽ��пռ�������ͷ�ʱ�ǻ���ù��캯��������������
// 
// C++�ж�̬�ڴ����ʽ��new/delete----���뵥�����͵Ŀռ�
// new[]/delete[]-----�����ͷ�һ�������Ŀռ�
//ע�⣺1��new/delete���Ǻ�������C++�еĹؼ���||������
//		2��new�Ŀռ����Ҫ��delete�ͷ�  new[]����ʹ��delete[]�ͷ�

//#if 0
//class Test
//{
//public:
//	Test()
//		:_t(10)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//	int _t;
//};
//
////new/delete��new[]/delete[]ʹ��˵��
//void Test1()
//{
//	int* p1 = new int;
//	int* p2 = new int(100);
//	int* p3 = new int[10];
//	int* p4 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };
//
//	delete p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//}
//void Test2()
//{
//	//malloc�����Ǵ�����һ��Test���͵Ķ���ֻ���ڶ���������һ����Test���ʹ�С��ͬ��һ��ռ�
//	//��Ϊ��malloc�����ù��캯��
//	Test* p1 = (Test*)malloc(sizeof(Test));//malloc������ù��캯��
//	if (nullptr == p1)
//		return;
//	
//	//����������һ�����󣬸ö���Ŀռ��ڶ���
//	Test* p2 = new Test;//new������ռ��ڼ����ù��캯��
//
//	free(p1);//:���ͷſռ��ڼ䣬���������������
//	delete p2;//:���ͷſռ��ڼ䣬����ö������������
//}
/*
��C++�У������Ҫ�ڶ�������ռ䣺
1������C�����е�malloc��calloc��realloc�����ǲ������������Ŀռ�
2������new/new[]---���Ե��ù��캯����ע�⣺���ʹ��new[]���������Ŀռ��ǣ���������ṩ�޲λ�ȫȱʡ�Ĺ��캯��
*/
//int main()
//{
//	Test2();
//	return 0;
//}
//
//#endif
//
//
//class Test
//{
//public:
//	Test()
//		:_t(10)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//	int _t;
//};
//
//int main()
//{
//	//���ٿռ� �� ���ù��캯��
//	Test* pt = new Test;
//	return 0;
//}
/*

//operator new���ú���ʵ��ͨ��malloc������ռ䣬��malloc����ռ�ɹ�ʱֱ�ӷ��أ�����ռ�ʧ�ܣ�
//����ִ�п� �䲻��Ӧ�Դ�ʩ�������Ӧ�Դ�ʩ�û������ˣ���������룬�������쳣��

void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc) {
	// try to allocate size bytes
	void* p;
	while ((p = malloc(size)) == 0)
		if (_callnewh(size) == 0)
		{
			// report no memory
			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
			static const std::bad_alloc nomem;
			_RAISE(nomem);
		}
	return (p);
}

//operator delete: �ú���������ͨ��free���ͷſռ��

void operator delete(void* pUserData) {
	_CrtMemBlockHeader* pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
	return;
	 _mlock(_HEAP_LOCK);// block other threads 
	__TRY
	// get a pointer to memory block header 
	pHead = pHdr(pUserData);
	// verify block type 
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
	_free_dbg(pUserData, pHead->nBlockUse);
	__FINALLY
	_munlock(_HEAP_LOCK); //release other threads
	__END_TRY_FINALLY
return; }
*/

//����
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//		
//	}
//};
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//	return 0;
//}

//class Test
//{
//public:
//	Test()
//		: _data(0)
//	{
//		cout << "Test():" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test():" << this << endl;
//	}
//
//private:
//	int _data;
//};
//void Test()
//{
//	// pt����ָ���ֻ��������Test������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ
//	Test* pt = (Test*)malloc(sizeof(Test));
//
//	new(pt) Test; // ע�⣺���Test��Ĺ��캯���в���ʱ���˴���Ҫ����
//}