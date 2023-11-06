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
	cout << "欢迎老师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.个人日程功能         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.团队日程功能         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;

}

std::string Teacher::formatInfo()
{
	stringstream ss;
	ss << this->m_teaId << " " << this->m_Name << " " << this->m_Pwd << endl;
	return ss.str();
}
