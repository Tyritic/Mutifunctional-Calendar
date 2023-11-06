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

	//Ĭ�Ϲ���
	Teacher();
	//�вι��� (ְ����ţ�����������)
	Teacher(string empId, string name, string pwd);
	bool operator==(const Teacher& right) const;
	//��ʾ�Ӳ˵� ��д����Identity���麯��
	virtual void openMenu() override;
	PersonalScheduleList personal;
	TeamScheduleList team;
	std::string formatInfo();//��ʽ���ַ���
	//��ʦ���
	string m_teaId;
};

