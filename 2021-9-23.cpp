#include<iostream>
using namespace std;

//void Swap(int& left, int& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right) {
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right) {
//	char temp = left;
//	left = right;
//	right = temp;
//}



//template<typename T>
//T Add(T& left, T& right) {
//	return left + right;
//}

//template<class T> 
//
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//int main()
//{
//	int a1 = 1, a2 = 2;
//	double d1 = 1.0, d2 = 2.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	Add(a, (int)d);
//	return 0;
//}
//template<class T>
//
//T Add(const T& left, const T& right) {
//	return left + right;
//}
//int main(void) {
//
//	// ��ʽʵ����
//	Add<int>(1, 12.0);
//	return 0;
//}


//// ��ͨ����
//int Add(int left, int right)
//{
//    return left + right;
//}
//// ����ģ��
//template<class T>
//T Add(T left, T right) {
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//    Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}

//
//// ��ͨ����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ����ģ��
//template<class T��class U>
//T Add(T left, U right) {
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//
//template<class T>
//
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		capacity = capacity < 10 ? 10 : capacity;
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	//���������������ⶨ��
//	~SeqList() {}
//private:
//	T* _array;
//	int _size;
//	int _capacity;
//};
//template<class T>
//SeqList<T>::~SeqList()
//{
//	if (_array)
//	{
//		delete[] _array;
//		_array = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//}
//
//int main()
//{
//	// SeqList������SeqList<int>��������
//	SeqList<int> s1;
//
//	SeqList<double> s2;
//}

//
//void Teststring1()
//{
//	// ע�⣺string�����֧��ֱ����cin��cout������������
//	string s("hello, bit!!!");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//
//	// ��s�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
//	s.clear();
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
//	// ��aaaaaaaaaa��
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
//	// "aaaaaaaaaa\0\0\0\0\0"
//	// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//	// ��s����Ч�ַ�������С��5��
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
////================================================================================
//void Teststring2()
//{
//	string s;
//	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//}
//// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
////================================================================================
//void TestPushBack()
//{
//	string s;
//	size_t sz = s.capacity();
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//void TestPushBackReserve()
//{
//	string s;
//	s.reserve(100);
//	size_t sz = s.capacity();
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//void Teststring()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//
//	s1[0] = 'H';
//	cout << s1 << endl;
//
//	// s2[0] = 'h'; �������ʧ�ܣ���Ϊconst���Ͷ������޸�
//}
//void Teststring()
//{
//	string s("hello Bit");
//	// 3�ֱ�����ʽ��
//	// ��Ҫע����������ַ�ʽ���˱���string���󣬻����Ա������޸�string�е��ַ���
//	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
//	// 1. for+operator[]
//	for (size_t i = 0; i < s.size(); ++i)
//		cout << s[i] << endl;
//
//	// 2.������
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	string::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//		cout << *rit << endl;
//
//	// 3.��Χfor
//	for (auto ch : s)
//		cout << ch << endl;
//}


//void Teststring()
//{
//	string str;
//	str.push_back(' '); // ��str�����ո�
//	str.append("hello"); // ��str��׷��һ���ַ�"hello"
//	str += 'b'; // ��str��׷��һ���ַ�'b' 
//	str += "it"; // ��str��׷��һ���ַ���"it"
//	cout << str << endl;
//	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//
//	// ��ȡfile�ĺ�׺
//	string file1("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//
//	// npos��string�����һ����̬��Ա����
//	// static const size_t npos = -1;
//
//	// ȡ��url�е�����
//	sring url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//
//	// ɾ��url��Э��ǰ׺
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}


//
//-**reverse��ת * *
//
//int main()
//{
//    string s("anmo");
//    cout << s << endl;//anmo
//    reverse(s.begin(), s.end());
//    cout << s << endl;//omna
//
//    system("pause");
//    return 0;
//}
//
//- **append��� * *
//
//int main()
//{
//    string s("I");
//    string s2(" anmo ");
//    s += " love ";
//    cout << s << endl;//I love
//    s += " you ";
//    cout << s << endl;//I love you
//    s.append(s2);
//    cout << s << endl;//I love you anmo
//    s.append("!!!");
//    cout << s << endl;//I love you anmo!!!
//
//
//    system("pause");
//    return 0;
//}
//
//- **insert���� * *
//
//int main()
//{
//    string s("IYOU");
//    s.insert(1, " LOVE ");
//    cout << s << endl;//I LOVE YOU
//
//    system("pause");
//    return 0;
//}
//
//- **erase��� find���� * *
//
//int main()
//{
//    string s("hello anmo");
//    cout << s << endl;//hello anmo
//    s.erase(s.begin() + s.find(" "), s.end());
//    cout << s << endl;//hello
//
//    //  ��ȡfile�ĺ�׺
//    string s1("hauhduadh.txt");
//    cout << s1 << endl;//hauhduadh.txt
//    s1.erase(s1.begin() + s1.find("."), s1.end());
//    cout << s1 << endl;//hauhduadh
//
//    system("pause");
//    return 0;
//}
//
//- **substr��ȡ rfind������� * *
//
//int main()
//{
//    string s("anmo.txt");
//    cout << s << endl;//anmo.txt
//    cout << s.substr(s.rfind(".") + 1) << endl;//txt
//
//    string s1("https://www.duba.com/?f=qlswdhq&tjiedb=1&ft=gjlock&--type=0");
//    int ret = s1.find(" : ") + 3;
//    cout << s1.substr(ret, s1.find("/", ret) - ret) << endl;//www.duba.com
//
//    system("pause");
//    return 0;
//}
//
//- push_back��append
//
//int main()
//{
//    string s;
//    s.push_back('I');//��s�����I
//    cout << s << endl;//I
//    s.append(" Love ");//��s��׷��һ���ַ���"Love"
//    cout << s << endl;//I Love
//    s += " you "; // ��s��׷��һ���ַ���'you'
//    cout << s << endl;//I Love  you
//    s += " anmo ";// ��s��׷��һ���ַ���"anmo" 
//    cout << s << endl;//I Love  you  anmo
//    s += '!';//��s��׷��һ���ַ�'!'
//    cout << s << endl;//I Love  you  anmo !
//
//
//    //��ȡfile��׺
//    string file("anmo.txt");
//    size_t pos = file.rfind('.');
//    cout << file.substr(pos + 1, file.size() - pos) << endl;//txt
//
//
//    system("pause");
//    return 0;
//}


//class string
//{
//public:
//	/*string()
//	:_str(new char[1])
//	{*_str = '\0';}
//	*/
//	//string(const char* str = "\0") ����ʾ��
//	//string(const char* str = nullptr) ����ʾ��
//	string(const char* str = "")
//	{
//		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};
//// ����
//void Teststring()
//{
//	string s1("hello bit!!!");
//	string s2(s1);
//}


//class string
//{
//public:
//	string(const char* str = "")
//	{
//		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//		if (nullptr == str)
//		{
//			assert(false);
//			return;
//		}
//
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	string(const string& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//
//	string& operator=(const string& s)
//	{
//		if (this != &s)
//		{
//			char* pStr = new char[strlen(s._str) + 1];
//			strcpy(pStr, s._str);
//			delete[] _str;
//			_str = pStr;
//		}
//
//		return *this;
//	}
//
//	~string()
//	{
//		if (_str)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};

//namespace bit
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//	public:
//		string(const char* str = "")
//		{
//			_size = strlen(str);
//			_capacity = _size;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		string(const string& s)
//			: _str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			string tmp(s);
//			this->Swap(tmp);
//		}
//		string& operator=(string s)
//		{
//			this->Swap(s);
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//		/////////////////////////////////////////////////////////////////
//		// iterator
//		iterator begin() { return _str; }
//		iterator end() { return _str + _size; }
//		/////////////////////////////////////////////////////////////////
//		// modify
//		void push_back(char c)
//		{
//			if (_size == _capacity)
//				Reserve(_capacity * 2);
//
//			_str[_size++] = c;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char c)
//		{
//			PushBack(c);
//			return *this;
//		}
//
//		// ��ҵʵ��
//		void append(const char* str);
//		string& operator+=(const char* str);
//		void clear()
//		{
//			_size = 0;
//			_str[_size] = '\0';
//		}
//		void swap(string& s)
//		{
//			swap(_str, s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//		}
//		const char* c_str()const
//		{
//			return _str;
//		}
//		/////////////////////////////////////////////////////////////////
//		// capacity
//		size_t size()const
//			size_t capacity()const
//			bool empty()const
//
//			void resize(size_t newSize, char c = '\0')
//		{
//			if (newSize > _size)
//			{
//				// ���newSize���ڵײ�ռ��С������Ҫ���¿��ٿռ�
//				if (newSize > _capacity)
//				{
//					Reserve(newSize);
//				}
//				memset(_str + _size, c, newSize - _size);
//			}
//			_size = newSize;
//			_str[newSize] = '\0';
//		}
//		void reserve(size_t newCapacity)
//		{
//			// ������������ھ��������򿪱ٿռ�
//			if (newCapacity > _capacity)
//			{
//				char* str = new char[newCapacity + 1];
//				strcpy(str, _str);
//				// �ͷ�ԭ���ɿռ�,Ȼ��ʹ���¿ռ�
//				delete[] _str;
//				_str = str;
//				_capacity = newCapacity;
//			}
//		}
//		////////////////////////////////////////////////////////////////////
//		// access
//		char& operator[](size_t index)
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		const char& operator[](size_t index)const
//		{
//			assert(index < _size);
//			return _str[index];
//		}
//		////////////////////////////////////////////////////////////////////
//		// ��ҵ
//		bool operator<(const string& s);
//		bool operator<=(const string& s);
//		bool operator>(const string& s);
//		bool operator>=(const string& s);
//		bool operator==(const string& s);
//		bool operator!=(const string& s);
//		// ����c��string�е�һ�γ��ֵ�λ��
//		size_t find(char c, size_t pos = 0) const;
//		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
//		size_t find(const char* s, size_t pos = 0) const;
//
//		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
//		string& insert(size_t pos, char c);
//		string& insert(size_t pos, const char* str);
//		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
//		string& erase(size_t pos, size_t len);
// private:
//	 friend ostream& operator<<(ostream& _cout, const bit::string& s);
//	 friend istream& operator>>(istream& _cin, bit::string& s);
// private:
//	 char* _str;
//	 size_t _capacity;
//	 size_t _size;
// };
//}
//ostream& bit::operator<<(ostream& _cout, const bit::string& s) {
//	// ����ʹ�����
//	//cout << s._str;
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		_cout << s[i];
//	}
//	return _cout;
//}
/////////���Զ����string����в���
//void TestBitstring()
//{
//	bit::string s1("hello");
//	s1.push_back(' ');
//	s1.push_back('b');
//	s1.append(1, 'i');
//	s1 += 't';
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	// ���õ�������ӡstring�е�Ԫ��
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// ������Կ���һ����ֻҪ֧�ֵĻ�����iterator����֧�ַ�Χfor
//	for (auto ch : s1)
//		cout << ch << " ";
//	cout << endl;
//}

// constructing vectors
//#include <iostream>
//#include <vector>
//int main()
//{
//	// constructors used in the same order as described above:
//	std::vector<int> first; // empty vector of ints
//	std::vector<int> second(4, 100); // four ints with value 100
//	std::vector<int> third(second.begin(), second.end()); // iterating through second
//	std::vector<int> fourth(third); // a copy of third
//	// �����漰��������ʼ���Ĳ��֣�����ѧϰ��������������ⲿ��
//	// the iterator constructor can also be used to construct from arrays:
//	int myints[] = { 16,2,77,29 };
//	std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//	std::cout << "The contents of fifth are:";
//	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//void PrintVector(const vector<int>& v) {
//	// const����ʹ��const���������б�����ӡ
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//int main()
//{
//	// ʹ��push_back����4������
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	// ʹ�õ��������б�����ӡ
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	// ʹ�õ����������޸�
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		++it;
//	}
//	// ʹ�÷�����������б����ٴ�ӡ
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//	PrintVector(v);
//	return 0;
//}

// push_back/pop_back
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ��posλ��֮ǰ����30
//	v.insert(pos, 30);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ�����
//	v.erase(pos);
//	it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };
//
//	auto it = v.begin();
//
//	// ����ЧԪ�ظ������ӵ�100���������λ��ʹ��8��䣬�����ڼ�ײ������
//	// v.resize(100, 8);
//
//	// reserve�����þ��Ǹı����ݴ�С�����ı���ЧԪ�ظ����������ڼ���ܻ�����ײ������ı�
//	// v.reserve(100);
//
//	// ����Ԫ���ڼ䣬���ܻ��������ݣ�������ԭ�ռ䱻�ͷ�
//	// v.insert(v.begin(), 0);
//	// v.push_back(8);
//
// // ��vector���¸�ֵ�����ܻ�����ײ������ı�
//	v.assign(100, 8);
//
//	/*
//	����ԭ�����ϲ��������п��ܻᵼ��vector���ݣ�Ҳ����˵vector�ײ�ԭ��ɿռ䱻�ͷŵ���
//   ���ڴ�ӡʱ��it��ʹ�õ����ͷ�֮��ľɿռ䣬�ڶ�it����������ʱ��ʵ�ʲ�������һ���Ѿ����ͷŵ�
//   �ռ䣬�������������ʱ������
//	�����ʽ�������ϲ������֮�������Ҫ����ͨ������������vector�е�Ԫ�أ�ֻ���it����
//   ��ֵ���ɡ�
//	*/
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//#include <vector>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	// ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
//	v.erase(pos);
//	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//#include <assert.h>
//// ע������namespace�����ȥ�Ͳ�Ҫȡ��Ϊbit�ˣ������ȥ���׷�����^^
//namespace bit
//{
//	template<class T>
//	class vector
//	{
//	public:
//		// Vector�ĵ�������һ��ԭ��ָ��
//		typedef T* iterator;
//		typedef const T* const_iterator;
//		iterator begin() { return _start; }
//		iterator end() { return _finish; }
//		const_iterator cbegin() const { return _start; }
//		const_iterator cend() const { return _finish; }
//		// construct and destroy
//		vector()
//			: _start(nullptr)
//			, _finish(nullptr)
//			, _endOfStorage(nullptr)
//		{}
//		vector(int n, const T& value = T())
//			: _start(nullptr)
//			, _finish(nullptr)
//			, _endOfStorage(nullptr) {
//			reserve(n);
//			while (n--)
//			{
//				push_back(value);
//			}
//		}
//		// ���ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����vector�ĵ�����
//		// ��������������������������[first,last]���������������ĵ�����
//		template<class InputIterator>
//		vector(InputIterator first, InputIterator last) {
//			reserve(last - first);
//			while (first != last)
//			{
//				push_back(*first);
//				++first;
//			}
//		}
//		vector(const vector<T>& v)
//			: _start(nullptr)
//			, _finish(nullptr)
//			, _endOfStorage(nullptr) {
//			reserve(v.capacity());
//			iterator it = begin();
//			const_iterator vit = v.cbegin();
//			while (vit != v.cend())
//			{
//				*it++ = *vit++;
//			}
//		}
//		vector<T>& operator=(vector<T> v) {
//			swap(v);
//			return *this;
//		}
//		~vector()
//		{
//			delete[] _start;
//			_start = _finish = _endOfStorage = nullptr;
//		}
//
//		// capacity
//		size_t size() const { return _finish - _start; }
//		size_t capacity() const { return _endOfStorage - _start; }
//		bool empty() const { return _first == _finish; }
//		void reserve(size_t n) {
//			if (n > capacity())
//			{
//				size_t oldSize = size();
//				T* tmp = new T[n];
//				// ����ֱ��ʹ��memcpy?
//				//if (_start)
//				// memcpy(tmp, _start, sizeof(T)*size);
//
//				if (_start)
//				{
//					for (size_t i = 0; i < oldSize; ++i)
//						tmp[i] = _start[i];
//				}
//				_start = tmp;
//				_finish = _start + size;
//				_endOfStorage = _start + n;
//			}
//		}
//		void resize(size_t n, const T& value = T())
//		{
//			// 1.���nС�ڵ�ǰ��size�������ݸ�����С��n
//			if (n <= size())
//			{
//				_finish = _start + n;
//				return;
//			}
//			// 2.�ռ䲻��������
//			if (n > capacity())
//				reserve(n);
//			// 3.��size����n
//			iterator it = _finish;
//			iterator _finish = _start + n;
//			while (it != _finish)
//			{
//				*it = value;
//				++it;
//			}
//		}
//		///////////////access///////////////////////////////
//		T& operator[](size_t pos) { return _start[pos]; }
//		const T& operator[](size_t pos)const { return _start[pos]; }
//
//		///////////////modify/////////////////////////////
//		void push_back(const T& x) { insert(end(), x); }
//		void pop_back() { erase(--end()); }
//
//		void swap(vector<T>& v) {
//			swap(_start, v._start);
//			swap(_finish, v._finish);
//			swap(_endOfStorage, v._endOfStorage);
//		}
//
//		iterator insert(iterator pos, const T& x) {
//			assert(pos <= _finish);
//			// �ռ䲻���Ƚ�������
//			if (_finish == _endOfStorage)
//			{
//				size_t size = size();
//				size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
//				reserve(newCapacity);
//				// ������������ݣ���Ҫ����pos
//				pos = _start + size;
//			}
//			iterator end = _finish - 1;
//			while (end >= pos)
//			{
//				*(end + 1) = *end;
//				--end;
//			}
//			*pos = x;
//			++_finish;
//			return pos;
//		}
//		// ����ɾ�����ݵ���һ������
//		// ������:һ�߱���һ��ɾ���ĵ�����ʧЧ����
//		iterator erase(Iterator pos) {
//			// Ų�����ݽ���ɾ��
//			iterator begin = pos + 1;
//			while (begin != _finish) {
//				*(begin - 1) = *begin;
//				++begin;
//			}
//			--_finish;
//			return pos;
//		}
//private:
//	iterator _start; // ָ�����ݿ�Ŀ�ʼ
//	iterator _finish; // ָ����Ч���ݵ�β
//	iterator _endOfStorage; // ָ��洢������β
//};
//}