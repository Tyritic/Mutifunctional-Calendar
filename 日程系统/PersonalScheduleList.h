#pragma once
#include<iostream>
#include<iomanip>
#include"PersonalScheduleNode.h"
#include<fstream>
class PersonalScheduleList
{
public:
    PersonalScheduleNode* head; // ͷ���
    PersonalScheduleNode* tail; // β���
public:
    // ���캯������ʼ��ͷ����β���
    PersonalScheduleList();
    // ���һ���ճ̣�����Ϊһ���ճ̶���
    void addPersonalSchedule(PersonalScheduleNode* s);
    // ɾ��һ���ճ̣�����Ϊһ�����ں�ʱ��
    void deletePersonalSchedule(string d, string t);
    // �޸�һ���ճ̣�����Ϊһ�����ڣ�ʱ����µ�����
    void modifyPersonalSchedule(string d, string t, int i);
    // ��ѯһ���ճ̣�����Ϊһ�����ں�ʱ��
    void queryPersonalSchedule(string d, string t);
    // ��ʾ�����ճ̣��������ں�ʱ������
    void showAllPersonalSchedules();
    void clearPersonalSchdules();

};

