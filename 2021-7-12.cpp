#include<stdio.h>

#include<iostream>
using namespace std;
//
//int a = 10;
//
//
//
////1����ͨ�������ռ�
////{}��ʾһ����Χ��������----�����ռ�ʵ�ʾ���һ�������ֵ�ֻ������
//namespace N1//N1Ϊ�����ռ������
//{
//    //�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
//    int a=20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//
////2�������ռ����Ƕ��----�����ռ��п��Զ��������ռ�
//namespace N2//N2Ϊ�����ռ������
//{
//    int a=30;
//    int b=30;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//    namespace N3
//    {
//        int a=40;
//        int b=40;
//        int Sub(int left, int right)
//        {
//            return left - right;
//        }
//    }
//}
//
//int main()
//{
//    int a = 50;
//    printf("%d\n", a);//main�ֲ�����a
//    printf("%d\n", ::a);//ȫ���������е�a
//    printf("%d\n", N1::a);//N1�����ռ��е�a
//    printf("%d\n", N2::a);//N2�����ռ��е�a
//    printf("%d\n", N2::N3::a);//N3�����ռ��е�a
//    return 0;
//}
//
//
//namespace N1//N1Ϊ�����ռ������
//{
//    //�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
//    int a = 20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//
////�������ռ��Աǰ����N1�����������ռ������Լ��������޶���)
////using N1::��Ա���֣�
//using N1::b;//b�൱�ڸ��ļ���ȫ�ֱ�����ʵ����b��N1�����ռ�ĳ�Ա��
//
//
////3��using namespace N1;
//using namespace N1;
////�ŵ㣺�����ռ��еĳ�Ա����ֱ���ڵ�ǰ�ļ���ֱ��ʹ��
////ȱ�㣺������ͻ�ĸ��ʱȽϴ�
//int main()
//{
//    printf("%d\n", N1::a);
//    printf("%d\n", b);
//    Add(a, b);
//    return 0;
//
//}
//
//
//namespace N1//N1Ϊ�����ռ������
//{
//    //�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
//    int a = 20;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//}
//namespace N1//N1Ϊ�����ռ������
//{
//    //�����ռ��е����ݣ��ȿ��Զ��������Ҳ���Զ��庯��
//    int c;
//    int d;
//    int Sub(int left, int right)
//    {
//        return left - right;
//    }
//}
//
//int main()
//{
//    int a;
//    int b;
//    int c;
//    cin >> a >> b >> c;
//    cout << 1 << " " << 1.23 << endl;
//    cout << "hello world" << endl;
//    return 0;
//}
//
//
////����ԭ�ͣ�����ֵ����  �������֣������б�{}
////c���Ա������Ժ���ԭ�ͼ��Ҫ���Ƿǳ��ϸ�
//void Test1()
//{
//    printf("Test1()\n");
//}
//int main()
//{
//    Test1();
//    return 0;
//}
//
//
////�ܷ����������Ĭ��ֵ
//void Test1(int a=0)
//{
//    printf("%d\n",a);
//}
//int main()
//{
//    Test1();
//    Test1(10);
//    return 0;
//}
//
//
//
////ȱʡ�������ࣺ
////1��ȫȱʡ����----���в���������Ĭ��ֵ
//
//void Func(int a = 1, int b = 2, int c = 3)
//{
//    cout << a << " " << b << " " << c << endl;
//}
//
////�������ι��򣺴�������һ�������ݲ���
////ȱʡ����ƥ����򣺴�����������ƥ��
//int main()
//{
//    Func();//��ӡ1,2,3
//    Func(10);//��ӡ10,2,3
//    Func(10, 20);//��ӡ10,20,3
//    Func(10, 20, 30);//��ӡ10,20,30
//}
//
//
//void Func(int a , int b = 2, int c = 3)
//{
//    cout << a << " " << b << " " << c << endl;
//}
//
////�������ι��򣺴�������һ�������ݲ���
////ȱʡ����ƥ����򣺴�����������ƥ��
//int main()
//{
//    //Func();//��ӡ1,2,3
//    //Func(10);//��ӡ10,2,3
//    //Func(10, 20);//��ӡ10,20,3
//    //Func(10, 20, 30);//��ӡ10,20,30
//    return 0;
//}
//
//
////һ��С�ģ������Ͷ���λ�ø�����Ĭ��ֵ���ܲ�һ�£��ڵ��õ�ʱ��Ӧ�����ĸ��ͻ�������⣬��** ����** ��λ�ø����ȽϺ�
//
//
//
////C�����У��������ֱ���Ψһ
//int Add(int left, int right)
//{
//    return left + right;
//}
//double Add(double left, double right)
//{
//    return left + right;
//}
//int main()
//{
//    Add(1, 2);//int,int--->Add(int,int)
//    Add(1.0, 2.0);//double,double--->ADD(double,double)
//    Add('1', '2');//û���ṩ�ַ������͵ļӷ�������char��int���Է�����ʽ���͵�ת��---->char,char-->��ʽ����ת��
//    Add(1,(int) 2.0);//int double ת����int int����double  double����������֪���������ת��---ֱ����ʾ����ת��
//}
//
//
////C�����У��������ֱ���Ψһ
//int Add(int left, int right)
//{
//    return left + right;
//}
//double Add(double left, double right)
//{
//    return left + right;
//}
//int main()
//{
//    Add(1, 2);//int,int--->Add(int,int)
//    Add(1.0, 2.0);//double,double--->ADD(double,double)
//    Add('1', '2');//û���ṩ�ַ������͵ļӷ�������char��int���Է�����ʽ���͵�ת��---->char,char-->��ʽ����ת��
//    Add(1, (int)2.0);//int double ת����int int����double  double����������֪���������ת��---ֱ����ʾ����ת��
//}
//
//
//
//int main()
//{
//    int a = 10;
//    int& ra = a;
//    ra = 100;
//    a = 200;
//    return 0;
//}
//
//
//
//void Swap(int& left, int& right)
//{
//
//    cout << &left << endl;
//    cout << &right << endl;
//    int temp = left;
//    left = right;
//    right = temp;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    cout << &a << endl;
//    cout << &b << endl;
//    Swap(a, b);
//    return 0;
//}
//
//
//int& Add(int left, int right)
//{
//    int temp = left + right;
//    return temp;
//}
//
//int main()
//{
//    int& ret = Add(1, 2);
//    Add(3, 4);
////    return 0;
////}
//#if 0
//
//#include<stdio.h>
//#include<string.h>
//
////C�����ж����ѧ���ṹ��
//struct Student
//{
//    char name[20];
//    char gender[3];
//    int age;
//};
//
////�������ѧ���ṹ��ķ���
//void InitStudent(Student* ps, char* name, char* gender, int age)
//{
//    strcpy(ps->name, name);
//    strcpy(ps->gender, gender);
//    ps->age = age; 
//}
//void PrintStudent(Student* ps)
//{
//    printf("%s-%s-%d\n", ps->name, ps->gender, ps->age);
//}
//int main()
//{
//    Student s1, s2, s3;
//    InitStudent(&s1, "peter", "��", 31);
//    InitStudent(&s2, "����", "Ů", 26);
//    InitStudent(&s3, "summer", "��", 2);
//    PrintStudent(&s1);
//    PrintStudent(&s2);
//    PrintStudent(&s3);
//    return 0;
//}
//#endif
//#include<iostream>
//using namespace std;

//class Date
//{
//public:
//	Date(int year, int month ,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void printDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//#if 0
//class Date
//{
//public:
//    //1���޲ι��캯��
//    Date()
//    {}
//
//    //2�����ι��캯��
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void TestDate()
//{
//    Date d1;//�����޲ι��캯��
//    Date d2(2019, 7, 27);//���ô��ι��캯��
//
//    //ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
//    //���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
//    Date d3();
//}
//
//int main()
//{
//	int a1;
//	int a2 = 0;
//	int a3(0);
//
//	Date d(2021, 9, 14);
//	//d.SetDate(2021, 9, 14);
//	d.printDate();
//	return 0;
//}
//
//
//class Date
//{
//public:
//    /*
//    //����û���ʾ�����˹��캯��������������������
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    */
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void TestDate()
//{
//    //û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
//    Date d1;
//}
//
//
//
//
//#include<assert.h>
//#include<malloc.h>
//class Seqlist
//{
//public:
//    Seqlist(int capacity = 10)
//    {
//        _pData = (int*)malloc(sizeof(int) * capacity);
//        assert(_pData);
//
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    ~Seqlist()
//    {
//        if (_pData)
//        {
//            free(_pData);//�ͷŶ��ϵĿռ�
//            _pData = NULL;//��ָ����Ϊ��
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//private:
//    int* _pData;
//    int _size;
//    int _capacity;
//};
//
//int main()
//{
//    return 0;
//}
//#endif

//
//class Date
//{
//public:
//	Date(int year=1970, int month=1 ,int day=1)
//        :_year(year)
//        ,_month(month)
//        ,_day(day)
//        ,count(0)
//	{
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(Date& d)
//        :_year(d._year)
//        ,_month(d._month)
//        ,_day(d._day)
//        ,count(++d.count)
//    {}
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//	void printDate()const
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//    int count;
//};
//
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    TestDate();
//    return 0;
//}


//int g_count = 0;
//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        g_count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        g_count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        g_count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
////����ȫ�ֱ����ǿ��Ե�
////��ȱ�ݣ�ȫ�ֱ��������к��������Է��ʵģ���һ���޸ļ����Ͳ�׼ȷ��
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    TestDate();
//    return 0;
//}


//�����У���û�й���ı���
//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//public:
//
//    //static���εĳ�Ա����---��Ϊ��̬��Ա����
//    static int count;//ע�⣺��̬��Ա����������ֻ��������������������г�ʼ��
//};
////��̬��Ա�����ĳ�ʼ����
////ע�⣺��̬��Ա������������г�ʼ���ǲ���Ҫ���static�ؼ���
//int Date::count = 0;
//void TestDate()
//{
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    Date d1;
//    Date d2(d1);
//    cout << &d1.count << " " << &d2.count << endl;
//    TestDate();
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year = 1970, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        count++;
//        cout << "Date(int,int,int):" << this << endl;
//    }
//    Date(Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        count++;
//        cout << "Date(Date& ):" << this << endl;
//    }
//
//    Date& operator=(const Date& d)
//    {
//        cout << this << "=" << &d << endl;
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//    ~Date()
//    {
//        count--;
//        cout << "~Date():" << this << endl;
//    }
//    void printDate()const
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//    static int GetCount()
//    {
//        return count;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    static int count;};
//int Date::count = 0;
//void TestDate()
//{
//    cout << Date::GetCount() << endl;
//    Date d1;
//    Date d2(d1);
//}
//int main()
//{
//    Date d1;
//    Date d2(d1);
//
//    cout << d1.GetCount() << endl;
//
//    TestDate();
////    return 0;
////}
//
//#if 0
//class Date;//ǰ������
//class Time
//{
//    friend class Date;//����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
//public:
//    Time(int hour, int minute, int second)
//        :_hour(hour)
//        , _minute(minute)
//        , _second(second)
//    {}
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//    void SetTimeOfDate(int hour, int minute, int second)
//    {
//        //ֱ�ӷ���ʱ����˽�г�Ա����
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};
//#endif
