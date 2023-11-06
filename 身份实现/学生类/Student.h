#pragma once
#include "Identity.h"
#include"PersonalScheduleList.h"
#include"TeamScheduleList.h"
#include<sstream>
class Student :
    public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(string id, string name, string password);
	bool operator==(const Student& right) const;
	//显示子菜单 重写父类Identity纯虚函数
	virtual void openMenu()  override;
	std::string formatInfo();//格式化字符串
	PersonalScheduleList personal;
	TeamScheduleList team;
	string m_Id;
};

