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
	cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
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

std::string Student::formatInfo()
{
	stringstream ss;
	ss << this->m_Id << " " << this->m_Name << " " << this->m_Pwd << endl;
	return ss.str();
}
