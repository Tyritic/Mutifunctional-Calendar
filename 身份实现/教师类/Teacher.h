#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"PersonalScheduleList.h"
#include"TeamScheduleList.h"
using namespace std;
#include "identity.h"
#include<sstream>
class Teacher :public Identity
{
public:

	//默认构造
	Teacher();
	//有参构造 (职工编号，姓名，密码)
	Teacher(string empId, string name, string pwd);
	bool operator==(const Teacher& right) const;
	//显示子菜单 重写父类Identity纯虚函数
	virtual void openMenu() override;
	PersonalScheduleList personal;
	TeamScheduleList team;
	std::string formatInfo();//格式化字符串
	//教师编号
	string m_teaId;
};

