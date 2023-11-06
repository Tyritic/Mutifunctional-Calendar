#pragma once
#include<iostream>
#include<iomanip>
#include"TeamScheduleNode.h"
#include<fstream>
class TeamScheduleList
{
public:
   TeamScheduleNode* head; // 头结点
   TeamScheduleNode* tail; // 尾结点
public:
    // 构造函数，初始化头结点和尾结点
   TeamScheduleList();
    // 添加一个日程，参数为一个日程对象
    void addTeamSchedule(TeamScheduleNode* s);
    // 删除一个日程，参数为一个日期和时间
    void deleteTeamSchedule(string d, string t);
    // 修改一个日程，参数为一个日期，时间和新的内容
    void modifyTeamSchedule(string d, string t, int i);
    // 查询一个日程，参数为一个日期和时间
    void queryTeamSchedule(string d, string t);
    // 显示所有日程，按照日期和时间排序
    void showAllTeamSchedules();
    void clearTeamSchdules();

};

