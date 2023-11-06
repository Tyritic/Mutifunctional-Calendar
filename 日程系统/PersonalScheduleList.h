#pragma once
#include<iostream>
#include<iomanip>
#include"PersonalScheduleNode.h"
#include<fstream>
class PersonalScheduleList
{
public:
    PersonalScheduleNode* head; // 头结点
    PersonalScheduleNode* tail; // 尾结点
public:
    // 构造函数，初始化头结点和尾结点
    PersonalScheduleList();
    // 添加一个日程，参数为一个日程对象
    void addPersonalSchedule(PersonalScheduleNode* s);
    // 删除一个日程，参数为一个日期和时间
    void deletePersonalSchedule(string d, string t);
    // 修改一个日程，参数为一个日期，时间和新的内容
    void modifyPersonalSchedule(string d, string t, int i);
    // 查询一个日程，参数为一个日期和时间
    void queryPersonalSchedule(string d, string t);
    // 显示所有日程，按照日期和时间排序
    void showAllPersonalSchedules();
    void clearPersonalSchdules();

};

