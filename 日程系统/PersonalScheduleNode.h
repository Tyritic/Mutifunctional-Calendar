#pragma once
#include <iostream>
#include <string>
#include <regex>
#include<stdexcept>
using namespace std;
// ����һ���ճ̽���࣬�������ڣ�ʱ�䣬���ݣ���Ҫ�Ե����ԣ��Լ�ָ����һ������ָ��
class PersonalScheduleNode 
{
public:
    string date; // ���ڣ���ʽΪyyyy-mm-dd
    string time; // ʱ�䣬��ʽΪhh:mm
    string content; // ����
    int priority; // ��Ҫ�ԣ�1-5֮���������1��ͣ�5���
    PersonalScheduleNode* next; // ָ����һ������ָ��
    // ���캯������ʼ������
    PersonalScheduleNode(string d,string t,string c,int p);
    
};
