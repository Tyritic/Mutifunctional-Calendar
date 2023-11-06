#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include<cstdio>
#include<sstream>
class Manager :public Identity
{
public:

	//默认构造
	Manager();

	//有参构造(管理员姓名，密码)
	Manager(string name, string pwd);

	//显示子菜单 重写父类Identity纯虚函数
	virtual void openMenu() override;

	//添加账号  
	void addPerson();
	void initVector();
	vector<Student>vStu;
	vector<Teacher>vTea;
	//查看账号
	void showPerson();
	//账号去重
	bool checkRepeat(string id, int type);
	//清空日程记录
	void cleanFile();
	//删除日程文件
	void deleteStudentSchedule();
	void deleteTeacherSchedule();
	void deleteTeamSchedule();
	//删除指定账号
	void deleteStudent();
	void deleteTeacher();
};


