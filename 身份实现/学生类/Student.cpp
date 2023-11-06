#include "Student.h"

Student::Student()
{
}

Student::Student(string id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

bool Student::operator==(const Student& right) const
{
	if (this->m_Id == right.m_Id&&this->m_Name==right.m_Name)return true;
	else return false;
}

void Student::openMenu()
{
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.�����ճ̹���         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�Ŷ��ճ̹���         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
	
}

std::string Student::formatInfo()
{
	stringstream ss;
	ss << this->m_Id << " " << this->m_Name << " " << this->m_Pwd << endl;
	return ss.str();
}
