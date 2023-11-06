#include "Manager.h"
//�вι���(����Ա����������)
Manager::Manager(string name, string password)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = password;
}
//ȫ�ֺ��� �������Ա�Ӳ˵�����

//ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	initVector();//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е����� ��ʱ��������
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.ɾ��ָ���˺�        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.ɾ���ճ��ļ�        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson()
{
	//��ʾ�û� ����������
	cout << "����������˺�����" << endl;
	cout << "1�������ѧ��" << endl;
	cout << "2������ӽ�ʦ" << endl;

	string filename;//�������ļ��� id
	string tip;//��ʾ�û������id
	string errortip;//id�ظ���ʾ
	ofstream ofs;//�ļ���������

	//�����û�ѡ���������
	int select = 0;
	cin >> select;

	if (select == 1)//���ѧ��
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�������������";
	}
	else//��ӽ�ʦ
	{
		filename = TEACHER_FILE;
		tip = "�����빤�ţ�";
		errortip = "�����ظ�������������";
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(filename, ios::app);

	//�����û������Ϣ
	string id;
	string name;
	string pwd;

	cout << tip;
	//�������ѧ�Ž����ظ��ж�
	while (1)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������";
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	//���ļ�������� �ո�ָ�
	ofs <<id << " " << name << " " << pwd << " "<<endl ;
	cout << "��ӳɹ���" << endl;

	ofs.close();
	system("pause");
	system("cls");

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е����� ��ʱ��������
	//this->initVector();
}


//��ʼ������
void Manager::initVector()
{
	//ѧ�� ��ʦ���� ���
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	//�ļ����ж�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	//����ѧ������
	Student s;

	//��ȡѧ����Ϣ������vStu��
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;//����
	
	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_teaId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	ifs.close();
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	

}

void Manager::showPerson()
{
	cout << "������鿴����" << endl;
	cout << "1�����鿴����ѧ���˺�" << endl;
	cout << "2�����鿴���н�ʦ�˺�" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		
		cout << "����ѧ����Ϣ���£�" << endl;
		for (auto Stu : vStu)
		{
			cout << "ѧ��ѧ�ţ�" << Stu.m_Id <<" " << "ѧ��������" << Stu.m_Name <<" " << "ѧ�����룺" << Stu.m_Pwd << endl;
		}
	}
	else
	{
		
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for (auto Tea  : vTea)
		{
			cout << "��ʦ���ţ�" << Tea.m_teaId << " " << "��ʦ������" << Tea.m_Name << " " << "��ʦ���룺" << Tea.m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ظ� ����1 ���ѧ��/���� ����2 ����������
bool Manager::checkRepeat(string id, int type)
{
	//������� ���ظ���ʾ
	if (type == 1)
	{
		//���ѧ��ѧ��
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//����ʦ����
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_teaId)
			{
				return true;
			}
		}
	}
	//Ĭ��û���ظ� 
	return false;
}

void Manager::cleanFile()
{
	int i;
	cout << "�������ָ��" << endl;
	cout << "1�����������ѧ���˺�" << endl;
	cout << "2����������н�ʦ�˺�" << endl;
	cin >> i;
	if (i == 1)
	{
		ofstream ofs(STUDENT_FILE, ios::trunc);
		ofs.close();
		cout << "�������ѧ����¼��" << endl;
		//vStu.clear();
		initVector();
		system("pause");
		system("cls");
	}
	else
	{
		ofstream ofs(TEACHER_FILE, ios::trunc);
		ofs.close();
		cout << "������н�ʦ��¼��" << endl;
		//vTea.clear();
		initVector();
		system("pause");
		system("cls");
	}
}

void Manager::deleteStudentSchedule()
{
	string id;
	string name;
	cout << "����ѧ��ѧ�ţ�"<<endl;
	cin >> id;
	cout << "����ѧ��������" << endl;
	cin >> name;
	string Path = "ѧ��ѧ�ţ�" + id + " " + "ѧ��������" + name + " " + "�����ճ�" + ".txt";
	if (remove(Path.c_str())==0)
	{
		cout << "ɾ���ճ��ļ��ɹ�" << endl;
	}
	else
	{
		cout << "ɾ���ճ��ļ�ʧ�ܣ������ļ�������" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeacherSchedule()
{
	string id;
	string name;
	cout << "�����ʦ���ţ�" << endl;
	cin >> id;
	cout << "�����ʦ������" << endl;
	cin >> name;
	string Path = "��ʦ���ţ�" + id + " " + "��ʦ������" + name + " " + "�����ճ�" + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "ɾ���ճ��ļ��ɹ�" << endl;
	}
	else
	{
		cout << "ɾ���ճ��ļ�ʧ�ܣ������ļ�������" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeamSchedule()
{
	string team;
	cout << "�������Ŷ����ƣ�" << endl;
	cin >> team;
	string Path = team + "�Ŷ��ճ�" + " " + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "ɾ���ճ��ļ��ɹ�" << endl;
	}
	else
	{
		cout << "ɾ���ճ��ļ�ʧ�ܣ������ļ�������" << endl;
	}
	system("pause");
	system("cls");

}

void Manager::deleteStudent()
{
	string id,name;
	cout << "������ѧ��ѧ�ţ�" << endl;
	cin >> id;
	cout << "������ѧ��������" << endl;
	cin >> name;
	Student stu;
	stringstream stream1(id);
	stringstream stream2(name);
	stream1 >> stu.m_Id;
	stream2 >> stu.m_Name;
	static std::vector<Student>::iterator delIt = vStu.end();
	delIt = std::find(vStu.begin(), vStu.end(), stu);//�����ճ̶���
	if (delIt != vStu.end())
	{
		vStu.erase(delIt);//ɾ������
		delIt = vStu.end();
		fstream write(STUDENT_FILE, ios::trunc | ios::out);//�Դ��ļ������ļ����ݸ�����գ�����ļ��������򴴽��ļ�
		if (!write.is_open())
		{
			cerr << STUDENT_FILE<< " ����ʧ��";
			return;
		}
		for (auto& stu : vStu)
		{
			string info = stu.formatInfo();//�����ʽ������ַ���
			write.write(info.c_str(), info.size());//д���ļ�
		}
		write.close();
	}
	string Path = "ѧ��ѧ�ţ�" + id + " " + "ѧ��������" + name + " " + "�����ճ�" + ".txt";;
	if (remove(Path.c_str()) == 0)
	{
		cout << "ɾ���ճ��ļ��ɹ�" << endl;
	}
	else
	{
		cout << "ɾ���ճ��ļ�ʧ�ܣ������ļ�������" << endl;
	}
	system("pause");
	system("cls");
}

void Manager::deleteTeacher()
{
	string id, name;
	cout << "�������ʦ���ţ�" << endl;
	cin >> id;
	cout << "�������ʦ������" << endl;
	cin >> name;
	Teacher tea;
	stringstream stream1(id);
	stringstream stream2(name);
	stream1 >> tea.m_teaId;
	stream2 >> tea.m_Name;
	static std::vector<Teacher>::iterator delIt = vTea.end();
	delIt = std::find(vTea.begin(), vTea.end(), tea);//���ҽ�ʦ����
	if (delIt != vTea.end())
	{
		vTea.erase(delIt);//ɾ������
		delIt = vTea.end();
		fstream write(TEACHER_FILE, ios::trunc | ios::out);//�Դ��ļ������ļ����ݸ�����գ�����ļ��������򴴽��ļ�
		if (!write.is_open())
		{
			cerr << TEACHER_FILE << " ����ʧ��";
			return;
		}
		for (auto& tea : vTea)
		{
			string info = tea.formatInfo();//�����ʽ������ַ���
			write.write(info.c_str(), info.size());//д���ļ�
		}
		write.close();
	}
	string Path = "��ʦ���ţ�" + id + " " + "��ʦ������" + name + " " + "�����ճ�" + ".txt";
	if (remove(Path.c_str()) == 0)
	{
		cout << "ɾ���ճ��ļ��ɹ�" << endl;
	}
	else
	{
		cout << "ɾ���ճ��ļ�ʧ�ܣ������ļ�������" << endl;
	}
	system("pause");
	system("cls");
}




