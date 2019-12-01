#include<iostream>
#include<string>
#include<fstream>						//�ļ���������������
#include<iomanip>
#include <algorithm>	
#include<vector>
using namespace std;
const char* filename = "Student.txt"; //ѧ����Ϣ��¼���ļ�����
class Date
{
	int year;
	short int month;
	short int day;
};
class Student
{
private:
	string Name;		//����
	long Number;		//ѧ��
	string Sex;			//�Ա�
	long Home;			//�����
	long Birthday;		//��������;
	Student* next;
public:
	Student(string na = "��", long num = 0, string sex = "��", long home=0,long birthday=0)
	{
		SetName(na);
		SetNumber(num);
		SetSex(sex);
		SetHome(home);
		SetBirthday(birthday);
		next = NULL;
	}
	~Student()					//����
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
	void SetName(string name)	{Name = name;} //��������
	void SetNumber(long num)	{Number = num;} //����ѧ��
	void SetSex(string sex)		{Sex = sex;	}
	void SetHome(int home)		{Home= home;}
	void SetBirthday(int birthday)   {Birthday = birthday; }
	friend istream& operator>>(istream& is, Student& T)//��������
	{
		string tmp;
		long num,home,birthday;
		cout << "������������";		
		is >> tmp;
		T.SetName(tmp);
		cout << "������ѧ�ţ�";
		is >> tmp;
		num = atol(tmp.c_str());		//�ַ���ת��Ϊ�����Σ�����������ַ�ʱ����ֵ�bug��
		T.SetNumber(num);
		cout << "�������Ա�";
		is >> tmp;
		T.SetSex(tmp);
		cout << "����������ţ�";
		is >> tmp;
		home = atol(tmp.c_str());
		T.SetHome(home);
		cout << "������������ڣ�";
		is >> tmp;
		birthday = atol(tmp.c_str());
		T.SetBirthday(birthday
		);
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& T)//�������
	{
		cout << left << setw(8) << T.Name << left << setw(15) << T.Number << left << setw(8) << T.Sex << left << setw(10) << T.Home << left << setw(10) << T.Birthday << endl;
		return os;
	}
	friend class  student_List;		//��Ԫ������
};
class student_List					//ѧ������Ϣ�����࣬��Ҫ��������Ĳ������������
{
private:
	Student* head;
public:
	student_List()					//ѧ������ĳ�ʼ��������ͷ���,�����ļ��ж�ȡ��Ϣ��������
	{
		head = new Student;
		head->next = NULL;
		ifstream ifs(filename);
		if (!ifs)					//����ļ�������
		{
			Filewrite();			//�����ļ�
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
	void Fileread()					//��ȡ�ļ��е���Ϣ��������
	{
		ifstream ifs(filename);
		if (!ifs)
		{
			cout << "�ļ���ʧ��" << endl;
			exit(0);
		}
		Student* q = head;
		while (ifs.peek() != EOF)		//�ж��Ƿ��ȡ���ļ�ĩβ�� �������peek������������ifs.eof()�Ƿ�ֹ�ļ�Ϊ��ʱ������ѭ��
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
	void Filewrite()				//ͨ���ļ��Ķ�д�������е�����д���ļ���
	{
		Student* p = head->next;
		ofstream ofs(filename);
		if (!ofs)
		{
			cout << "�ļ���ʧ��" << endl;
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
	void Putin(int n = 1)			//����,�����ĺ������������ǲ���1�����뻹�ǲ���....Ĭ�������뺯��
	{
		char x = '0';
		int i = 1;				//����
		int num_0, num_1;//����λ��
		Student* q;
		if (n == 1)				//���ǲ���������������Ҫ�ģ����������������Ҫ
		{
			cout << "�Ƿ����ԭ������ 0.�ǵ�	1.��������Ϣ		3.���� ";
			cin >> x;
			if (x == '1')//��ӽ�ȥ
			{
				Fileread();				//��ȡ�ļ��γ�����
				Putin(0);				//�����ĸı�,���ǲ��뺯���ĵ���
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
				if (n != 3)//�ڵ�Ĳ巨
				{
					p->next = head->next;
					head->next = p;
				}
				else//�ڵ������λ�ò���
				{
					Display(2);
					cout << "----------------------------------------------------------------" << endl;
					cout << "��ѡ�����λ�ã�";
					cin >> x;
					num_0 = x - '0';
					q = head;
					num_1 = 0;//Ѱ��λ��
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
				cout << "������Ҫ����ô����0.��		1.�� "<<endl;
				cin >> x;
				cout << "----------------------------------------------------------------" << endl;
			}
			Filewrite();
		}
	}
	void Display(int x = 1)				//��ʾ���cout<<left<<setw(40)<<"�������"<<left<<setw(35)<<"�������"<<endl;
	{
		if (x == 1)
			Fileread();
		cout << left << setw(5) << "����š�" << left << setw(8) << " ��������" << left << setw(8) << " ��ѧ�š�" << left << setw(8) << "���Ա�" << left << setw(8) << "������š�" << left << setw(8) << "���������ڡ�" << endl;
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
	void Insert()				//����(���)
	{
		Fileread();				//��ȡ�ļ��γ�����
		Putin(3);				//�����ĸı�,���ǲ��뺯���ĵ���
	}
	void Delete()				//ɾ��
	{
		Find(2);
		Filewrite();		//д���ļ�
	}
	void Find(int i = 1)			//����
	{
		Fileread();//��ȡ�ļ��γ�����
		char x = '0';
		while (x == '0')
		{
			cout << "ѡ����ҷ�ʽ��	1.����	 2.ѧ��	  0.����";
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
				cout << "ѡ����󣡣���";
			}
			cout << "�Ƿ�������� 0.���� 1.����  ";
			cin >> x;
		}
		Filewrite();
	}
	void Find_01name(int x = 1)	//�������� ���� 1.���� 2.ɾ�� 3.�޸�
	{
		int i = 0;
		string na;
		char x_0 = '1';
		Student* p = head->next, * q = head;
		cout << "������Ҫ���ҵ�������";
		cin >> na;
		cout << left << setw(5) << "����š�" << left << setw(8) << " ��������" << left << setw(15) << " ��ѧ�š�" << left << setw(8) << "���Ա�" << left << setw(10) << "������š�" << left << setw(10) << "���������ڡ�" << endl;
		while (p != NULL)
		{
			if (p->Name == na)
			{
				cout << left << setw(3) << " " << left << setw(3) << i++ << "    " << *p;
				if (x == 2)//ɾ������
				{
					cout << "�Ƿ�ɾ���������� 0.�� 1.��";
					cin >> x_0;
					if (x_0 == '0')
					{
						q->next = p->next;
						delete p;
						p = q;
					}
				}
				if (x == 3)//�޸�����
				{
					cout << "�Ƿ��޸���������	0.��		1.��";
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
			cout << "�õ��İȣ�û����Ҫ������" << endl;
	}
	void Find_02number(int x = 1)//ѧ�Ų���
	{
		int i = 0;
		long num;
		string tmp;
		char x_0 = '1';
		Student* p = head->next, * q = head;
		cout << "������Ҫ���ҵ�ѧ�ţ�";
		cin >> tmp;
		num = atol(tmp.c_str());
		cout << left << setw(5) << "����š�" << left << setw(8) << " ��������" << left << setw(15) << " ��ѧ�š�" << left << setw(8) << "���Ա�" << left << setw(10) << "������š�" << left << setw(10) << "���������ڡ�" << endl;
		while (p != NULL)
		{
			if (p->Number == num)
			{
				cout << left << setw(3) << " " << left << setw(3) << i++ << "    " << *p;
				if (x == 2)//ɾ������
				{
					cout << "�Ƿ�ɾ���������� 0.�� 1.��";
					cin >> x_0;
					if (x_0 == '0')
					{
						q->next = p->next;
						delete p;
						p = q;
					}
				}
				if (x == 3)//�޸�����
				{
					cout << "�Ƿ��޸���������	0.��		1.��";
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
			cout << "�õ��İȣ�û����Ҫ������" << endl;
	}
	void Change()		//�޸�             
	{
		Find(3);
		Filewrite();		//д���ļ�
	}
	void Change_s(Student * p)
	{
		char a = '0';
		string tmp;
		long num,home,birthday;
		while (a == '0')
		{
			cout << "-------------------------------------------------------" << endl;
			cout << "��ѡ���޸�ѡ��   1.���� 2.ѧ�� 3.�Ա� 4.����� 5.��������";
			cin >> a;
			cout << "-------------------------------------------------------" << endl;
			switch (a)
			{
			case '1':
				cout << "�������֣�";
				cin >> tmp;
				p->SetName(tmp);
				break;
			case '2':
				cout << "����ѧ�ţ�";
				cin >> tmp;
				num = atol(tmp.c_str());
				p->SetNumber(num);
				break;
			case '3':
				cout << "�����Ա�";
				cin >> tmp;
				p->SetSex(tmp);
				break;
			case '4':
				cout << "��������ţ�";
				cin >> tmp;
				home = atol(tmp.c_str());
				p->SetHome(home);
				break;
			case '5':
				cout << "������������ڣ�";
				cin >> tmp;
				birthday = atol(tmp.c_str());
				p->SetBirthday(birthday);
				break;
			default:
				cout << "�����������" << endl;
			}
			cout << *p;
			cout << "-------------------------------------------------------" << endl;//�����Ӿ�Ч��
			cout << "�Ƿ�����޸�����ѡ�� 0.���� 1.����";
			cin >> a;
		}
	}
	void student_pass(string na, string num)		//ѧ����½���
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
			cout << "���޴��ˣ���ϵͳ����ʶ�㣡";
			cin.get(); cin.get();
			return;
		}
		int i = 0;
		system("cls");
		cout << endl << endl << "������" << p->Name << " ѧ�ţ�" << p->Number << " �Ա�" << p->Sex << " ����ţ�" << p->Home << " ���գ�" << p->Birthday << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cin.get();
		cin.get();
	}
	void Write()
	{
		cout<<"�ļ�д��ɹ�" <<endl;
		Filewrite();
	}
};
const string Pass_word = "123456";//��ʦ��½����
void Meue_studentpass()//ѧ����½
{
	student_List B;
	string na, num;
	cout << "\n\n������ѧ�ţ�";
	cin >> num;
	cout << "���������֣�";
	cin >> na;
	B.student_pass(na, num);
}
void Meue()				//���˵�����
{
	while (1)
	{
		system("cls");
		cout << "  ���������п����뱳���ľ�ͷ����������ˮ��Ĵ�������������  " << endl;
		cout << "                    �x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x				 " << endl;
		cout << "                            1.��ʾ��Ϣ          			 		 " << endl;
		cout << "                            2.�����Ϣ          				 	 " << endl;//��ɿ��������λ�õ�
		cout << "                            3.������Ϣ          					 " << endl;
		cout << "                            4.ɾ����Ϣ          				     " << endl;
		cout << "                            5.�޸���Ϣ		   				 		 " << endl;	
		cout << "                            6.������Ϣ          				     " << endl;
		cout << "                            7.������Ϣ          					 " << endl;
		cout << "                            0.�˳���½          				 	 " << endl;		
		cout << "                    ��������������������������������				 " << endl;
		cout << " ���������������������������������� " << endl;
		student_List A;//��������,��ʼ��
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
		default: cout << "ѡ�����";
			break;
		}
	}
}
void Welcome()			//��ʼ�ĵ�½����
{
	system("cls");
	cout << "\t\t ��ѧ����Ϣ����ϵͳ��" << endl;
	cout << "\t\t�~�~�~�~�~�~�~�~�~�~�~" << endl;
	cout << "\t\t��                  ��" << endl;
	cout << "\t\t��    1.��ʦ��¼    ��" << endl;	
	cout << "\t\t��    2.ѧ����¼    ��" << endl;
	cout << "\t\t��    0.��   ��     ��" << endl;
	cout << "\t\t��                  ��" << endl;
	cout << "\t\t�~�~�~�~�~�~�~�~�~�~�~" <<endl;
	char x;
	string tmp;
	cout<<"��ѡ��:"; 
	cin >> x;
	switch (x)
	{
	case '0':cout<<"�밴������˳�";	exit(0);
	case '1':
		cout <<"���������룺";
		cin >> tmp;
		if (tmp == Pass_word)					//�ж��Ƿ�ͨ������
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
