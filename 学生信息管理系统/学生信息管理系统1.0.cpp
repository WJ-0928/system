#include<iostream>
#include<string>
#include<fstream>						//文件的输出输出流操作
#include<iomanip>
#include <algorithm>	
#include<vector>
using namespace std;
const char* filename = "Student.txt"; //学生信息记录的文件名称
class Date
{
	int year;
	short int month;
	short int day;
};
class Student
{
private:
	string Name;		//姓名
	long Number;		//学号
	string Sex;			//性别
	long Home;			//宿舍号
	long Birthday;		//出生日期;
	Student* next;
public:
	Student(string na = "空", long num = 0, string sex = "男", long home=0,long birthday=0)
	{
		SetName(na);
		SetNumber(num);
		SetSex(sex);
		SetHome(home);
		SetBirthday(birthday);
		next = NULL;
	}
	~Student()					//析构
	{
		Name = ""; Number = 0; Sex = "";Home = 0; Birthday = 0; next = NULL;
	}
	Student& operator =(const Student& T)
	{
		Name = T.Name;
		Number = T.Number;
		Sex = T.Sex;
		Home = T.Home;
		Birthday = T.Birthday;
		return *this;
	}
	void SetName(string name)	{Name = name;} //设置名字
	void SetNumber(long num)	{Number = num;} //设置学号
	void SetSex(string sex)		{Sex = sex;	}
	void SetHome(int home)		{Home= home;}
	void SetBirthday(int birthday)   {Birthday = birthday; }
	friend istream& operator>>(istream& is, Student& T)//输入数据
	{
		string tmp;
		long num,home,birthday;
		cout << "请输入姓名：";		
		is >> tmp;
		T.SetName(tmp);
		cout << "请输入学号：";
		is >> tmp;
		num = atol(tmp.c_str());		//字符型转化为长整形（解决了输入字符时会出现的bug）
		T.SetNumber(num);
		cout << "请输入性别：";
		is >> tmp;
		T.SetSex(tmp);
		cout << "请输入宿舍号：";
		is >> tmp;
		home = atol(tmp.c_str());
		T.SetHome(home);
		cout << "请输入出生日期：";
		is >> tmp;
		birthday = atol(tmp.c_str());
		T.SetBirthday(birthday
		);
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& T)//输出数据
	{
		cout << left << setw(8) << T.Name << left << setw(15) << T.Number << left << setw(8) << T.Sex << left << setw(10) << T.Home << left << setw(10) << T.Birthday << endl;
		return os;
	}
	friend class  student_List;		//友元类设置
};
class student_List					//学生的信息链表类，主要进行链表的操作，查找输出
{
private:
	Student* head;
public:
	student_List()					//学生链表的初始化，建立头结点,并从文件中读取信息建立链表
	{
		head = new Student;
		head->next = NULL;
		ifstream ifs(filename);
		if (!ifs)					//如果文件不存在
		{
			Filewrite();			//建立文件
		}
	}
	~student_List()
	{
		Student* p = head->next, * q;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
		delete head;
	}
	void Fileread()					//读取文件中的信息建立链表
	{
		ifstream ifs(filename);
		if (!ifs)
		{
			cout << "文件打开失败" << endl;
			exit(0);
		}
		Student* q = head;
		while (ifs.peek() != EOF)		//判断是否读取到文件末尾了 采用这个peek函数而不采用ifs.eof()是防止文件为空时还进入循环
		{
			Student* p = new Student;
			ifs >> p->Name
				>> ws
				>> p->Number
				>> ws
				>> p->Sex
				>> ws
				>> p->Home
				>> ws
				>> p->Birthday
				>> ws;
			q->next = p;
			p->next = NULL;
			q = p;
		}
	}
	void Filewrite()				//通过文件的读写将链表中的内容写到文件中
	{
		Student* p = head->next;
		ofstream ofs(filename);
		if (!ofs)
		{
			cout << "文件打开失败" << endl;
			exit(0);
		}
		while (p != NULL)
		{
			ofs << p->Name << '\t'
				<< p->Number << '\t' << p->Sex << '\t' << p->Home << '\t' << p->Birthday
				<< endl;
			ofs << endl;
			p = p->next;
		}
		ofs.close();
	}
	void Putin(int n = 1)			//输入,参数的含义是区别与是操作1的输入还是插入....默认是输入函数
	{
		char x = '0';
		int i = 1;				//计数
		int num_0, num_1;//插入位置
		Student* q;
		if (n == 1)				//这是操作输入数据是需要的，如果插入数据则不需要
		{
			cout << "是否清空原来数据 0.是的	1.否，增加信息		3.返回 ";
			cin >> x;
			if (x == '1')//添加进去
			{
				Fileread();				//读取文件形成链表
				Putin(0);				//参数的改变,就是插入函数的调用
				return;
			}
		}
		if (x == '0')
		{
			while (x == '0')
			{
				cout << i++ << endl;
				Student* p = new Student;
				cin >> *p;
				if (n != 3)//节点的插法
				{
					p->next = head->next;
					head->next = p;
				}
				else//节点的任意位置插入
				{
					Display(2);
					cout << "----------------------------------------------------------------" << endl;
					cout << "请选择插入位置：";
					cin >> x;
					num_0 = x - '0';
					q = head;
					num_1 = 0;//寻找位置
					while (q->next != NULL)
					{
						num_1++;
						if (num_0 == num_1)			break;
						q = q->next;
					}
					p->next = q->next;
					q->next = p;
					Display(2);
				}
				cout << "请问是要继续么？（0.是		1.否） "<<endl;
				cin >> x;
				cout << "----------------------------------------------------------------" << endl;
			}
			Filewrite();
		}
	}
	void Display(int x = 1)				//显示输出cout<<left<<setw(40)<<"靠左输出"<<left<<setw(35)<<"靠左输出"<<endl;
	{
		if (x == 1)
			Fileread();
		cout << left << setw(5) << "·序号·" << left << setw(8) << " ·姓名·" << left << setw(8) << " ·学号·" << left << setw(8) << "·性别·" << left << setw(8) << "·宿舍号·" << left << setw(8) << "·出生日期·" << endl;
		Student * p = head->next;
		int i = 1;
		while (p != NULL)
		{
			cout << left << setw(3) << " " << left << setw(3) << i++ << "    " << *p;
			p = p->next;
		}
		cin.get();
		cin.get();
		Filewrite();
	}
	void Insert()				//插入(添加)
	{
		Fileread();				//读取文件形成链表
		Putin(3);				//参数的改变,就是插入函数的调用
	}
	void Delete()				//删除
	{
		Find(2);
		Filewrite();		//写入文件
	}
	void Find(int i = 1)			//查找
	{
		Fileread();//读取文件形成链表
		char x = '0';
		while (x == '0')
		{
			cout << "选择查找方式：	1.姓名	 2.学号	  0.返回";
			cin >> x;
			switch (x)
			{
			case '1':
				Find_01name(i);
				break;
			case '2':
				Find_02number(i);
				break;
			case '0':return;
			default:
				cout << "选择错误！！！";
			}
			cout << "是否继续查找 0.继续 1.放弃  ";
			cin >> x;
		}
		Filewrite();
	}
	void Find_01name(int x = 1)	//查找名字 参数 1.查找 2.删除 3.修改
	{
		int i = 0;
		string na;
		char x_0 = '1';
		Student* p = head->next, * q = head;
		cout << "请输入要查找的姓名：";
		cin >> na;
		cout << left << setw(5) << "·序号·" << left << setw(8) << " ·姓名·" << left << setw(15) << " ·学号·" << left << setw(8) << "·性别·" << left << setw(10) << "·宿舍号·" << left << setw(10) << "·出生日期·" << endl;
		while (p != NULL)
		{
			if (p->Name == na)
			{
				cout << left << setw(3) << " " << left << setw(3) << i++ << "    " << *p;
				if (x == 2)//删除数据
				{
					cout << "是否删除这条数据 0.是 1.否";
					cin >> x_0;
					if (x_0 == '0')
					{
						q->next = p->next;
						delete p;
						p = q;
					}
				}
				if (x == 3)//修改数据
				{
					cout << "是否修该这条数据	0.是		1.否";
					cin >> x_0;
					if (x_0 == '0')
					{
						Change_s(p);
					}
				}
			}
			q = p;
			p = p->next;
		}cout << "-------------------------------------------------------" << endl;
		if (i == 0)
			cout << "用点心叭，没有需要的数据" << endl;
	}
	void Find_02number(int x = 1)//学号查找
	{
		int i = 0;
		long num;
		string tmp;
		char x_0 = '1';
		Student* p = head->next, * q = head;
		cout << "请输入要查找的学号：";
		cin >> tmp;
		num = atol(tmp.c_str());
		cout << left << setw(5) << "·序号·" << left << setw(8) << " ·姓名·" << left << setw(15) << " ·学号·" << left << setw(8) << "·性别·" << left << setw(10) << "·宿舍号·" << left << setw(10) << "·出生日期·" << endl;
		while (p != NULL)
		{
			if (p->Number == num)
			{
				cout << left << setw(3) << " " << left << setw(3) << i++ << "    " << *p;
				if (x == 2)//删除数据
				{
					cout << "是否删除这条数据 0.是 1.否";
					cin >> x_0;
					if (x_0 == '0')
					{
						q->next = p->next;
						delete p;
						p = q;
					}
				}
				if (x == 3)//修改数据
				{
					cout << "是否修该这条数据	0.是		1.否";
					cin >> x_0;
					if (x_0 == '0')
					{
						Change_s(p);
					}
				}
			}
			q = p;
			p = p->next;
		}
		cout << "-------------------------------------------------------" << endl;
		if (i == 0)
			cout << "用点心叭，没有需要的数据" << endl;
	}
	void Change()		//修改             
	{
		Find(3);
		Filewrite();		//写入文件
	}
	void Change_s(Student * p)
	{
		char a = '0';
		string tmp;
		long num,home,birthday;
		while (a == '0')
		{
			cout << "-------------------------------------------------------" << endl;
			cout << "请选择修改选项   1.姓名 2.学号 3.性别 4.宿舍号 5.出生日期";
			cin >> a;
			cout << "-------------------------------------------------------" << endl;
			switch (a)
			{
			case '1':
				cout << "输入名字：";
				cin >> tmp;
				p->SetName(tmp);
				break;
			case '2':
				cout << "输入学号：";
				cin >> tmp;
				num = atol(tmp.c_str());
				p->SetNumber(num);
				break;
			case '3':
				cout << "输入性别：";
				cin >> tmp;
				p->SetSex(tmp);
				break;
			case '4':
				cout << "输入宿舍号：";
				cin >> tmp;
				home = atol(tmp.c_str());
				p->SetHome(home);
				break;
			case '5':
				cout << "请输入出生日期：";
				cin >> tmp;
				birthday = atol(tmp.c_str());
				p->SetBirthday(birthday);
				break;
			default:
				cout << "笨蛋，输错啦" << endl;
			}
			cout << *p;
			cout << "-------------------------------------------------------" << endl;//美化视觉效果
			cout << "是否继续修改其他选项 0.继续 1.不了";
			cin >> a;
		}
	}
	void student_pass(string na, string num)		//学生登陆情况
	{
		Fileread();
		Student* p = head->next;
		while (p != NULL)
		{
			if (p->Name == na && p->Number == atol(num.c_str()))
				break;
			p = p->next;
		}
		if (p == NULL)
		{
			cout << "查无此人，本系统不认识你！";
			cin.get(); cin.get();
			return;
		}
		int i = 0;
		system("cls");
		cout << endl << endl << "姓名：" << p->Name << " 学号：" << p->Number << " 性别：" << p->Sex << " 宿舍号：" << p->Home << " 生日：" << p->Birthday << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cin.get();
		cin.get();
	}
	void Write()
	{
		cout<<"文件写入成功" <<endl;
		Filewrite();
	}
};
const string Pass_word = "123456";//教师登陆密码
void Meue_studentpass()//学生登陆
{
	student_List B;
	string na, num;
	cout << "\n\n请输入学号：";
	cin >> num;
	cout << "请输入名字：";
	cin >> na;
	B.student_pass(na, num);
}
void Meue()				//主菜单界面
{
	while (1)
	{
		system("cls");
		cout << "  ★★★★★所有苦难与背负的尽头都是行云流水般的此世光阴★★★★★  " << endl;
		cout << "                    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁				 " << endl;
		cout << "                            1.显示信息          			 		 " << endl;
		cout << "                            2.添加信息          				 	 " << endl;//变成课任意插入位置的
		cout << "                            3.查找信息          					 " << endl;
		cout << "                            4.删除信息          				     " << endl;
		cout << "                            5.修改信息		   				 		 " << endl;	
		cout << "                            6.保存信息          				     " << endl;
		cout << "                            7.插入信息          					 " << endl;
		cout << "                            0.退出登陆          				 	 " << endl;		
		cout << "                    ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔				 " << endl;
		cout << " ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★ " << endl;
		student_List A;//建立链表,初始化
		char t;
		cin >> t;
		system("cls");
		switch (t)
		{
		case '1':
			A.Display();
			break;
		case '2':
			A.Insert();
			break;
		case '3':
			A.Find();
			break;
		case '4':
			A.Delete();
			break;
		case '5':
			A.Change();
			break;
		case '6':
			A.Write();
			break;
		case '7':
			A.Putin();
			break;
		case '0': return;
		default: cout << "选择错误";
			break;
		}
	}
}
void Welcome()			//开始的登陆界面
{
	system("cls");
	cout << "\t\t ☆学生信息管理系统☆" << endl;
	cout << "\t\t▇▇▇▇▇▇▇▇▇▇▇" << endl;
	cout << "\t\t★                  ★" << endl;
	cout << "\t\t★    1.教师登录    ★" << endl;	
	cout << "\t\t★    2.学生登录    ★" << endl;
	cout << "\t\t★    0.退   出     ★" << endl;
	cout << "\t\t★                  ★" << endl;
	cout << "\t\t▇▇▇▇▇▇▇▇▇▇▇" <<endl;
	char x;
	string tmp;
	cout<<"请选择:"; 
	cin >> x;
	switch (x)
	{
	case '0':cout<<"请按任意键退出";	exit(0);
	case '1':
		cout <<"请输入密码：";
		cin >> tmp;
		if (tmp == Pass_word)					//判断是否通过密码
			Meue();
		break;
	case '2':
		Meue_studentpass();
		break;
	}
}
int main()
{
	while (1)
		Welcome();
	return 0;
}
