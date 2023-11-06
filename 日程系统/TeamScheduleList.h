#pragma once
#include<iostream>
#include<iomanip>
#include"TeamScheduleNode.h"
#include<fstream>
class TeamScheduleList
{
public:
   TeamScheduleNode* head; // ͷ���
   TeamScheduleNode* tail; // β���
public:
    // ���캯������ʼ��ͷ����β���
   TeamScheduleList();
    // ���һ���ճ̣�����Ϊһ���ճ̶���
    void addTeamSchedule(TeamScheduleNode* s);
    // ɾ��һ���ճ̣�����Ϊһ�����ں�ʱ��
    void deleteTeamSchedule(string d, string t);
    // �޸�һ���ճ̣�����Ϊһ�����ڣ�ʱ����µ�����
    void modifyTeamSchedule(string d, string t, int i);
    // ��ѯһ���ճ̣�����Ϊһ�����ں�ʱ��
    void queryTeamSchedule(string d, string t);
    // ��ʾ�����ճ̣��������ں�ʱ������
    void showAllTeamSchedules();
    void clearTeamSchdules();

};

