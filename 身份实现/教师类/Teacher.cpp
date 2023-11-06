#include "Teacher.h"

Teacher::Teacher()
{
}
Teacher::Teacher(string id, string name, string password)
{
	this->m_teaId = id;
	this->m_Name = name;
	this->m_Pwd = password;
}
bool Teacher::operator==(const Teacher& right) const
{
	if (this->m_teaId == right.m_teaId && this->m_Name == right.m_Name)return true;
	else return false;
}
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
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

std::string Teacher::formatInfo()
{
	stringstream ss;
	ss << this->m_teaId << " " << this->m_Name << " " << this->m_Pwd << endl;
	return ss.str();
}
