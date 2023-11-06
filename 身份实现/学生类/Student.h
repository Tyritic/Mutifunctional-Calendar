#pragma once
#include "Identity.h"
#include"PersonalScheduleList.h"
#include"TeamScheduleList.h"
#include<sstream>
class Student :
    public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(string id, string name, string password);
	bool operator==(const Student& right) const;
	//��ʾ�Ӳ˵� ��д����Identity���麯��
	virtual void openMenu()  override;
	std::string formatInfo();//��ʽ���ַ���
	PersonalScheduleList personal;
	TeamScheduleList team;
	string m_Id;
};

