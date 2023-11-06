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

	//Ĭ�Ϲ���
	Manager();

	//�вι���(����Ա����������)
	Manager(string name, string pwd);

	//��ʾ�Ӳ˵� ��д����Identity���麯��
	virtual void openMenu() override;

	//����˺�  
	void addPerson();
	void initVector();
	vector<Student>vStu;
	vector<Teacher>vTea;
	//�鿴�˺�
	void showPerson();
	//�˺�ȥ��
	bool checkRepeat(string id, int type);
	//����ճ̼�¼
	void cleanFile();
	//ɾ���ճ��ļ�
	void deleteStudentSchedule();
	void deleteTeacherSchedule();
	void deleteTeamSchedule();
	//ɾ��ָ���˺�
	void deleteStudent();
	void deleteTeacher();
};


