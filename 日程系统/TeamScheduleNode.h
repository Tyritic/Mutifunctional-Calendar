#pragma once
#include <iostream>
#include <string>
#include <regex>
#include<stdexcept>
using namespace std;
// 定义一个日程结点类，包含日期，时间，内容，重要性等属性，以及指向下一个结点的指针
class TeamScheduleNode
{
public:
    string id;//学号
    string name;//姓名
    string date; // 日期，格式为yyyy-mm-dd
    string time; // 时间，格式为hh:mm
    string content; // 内容
    int priority; // 重要性，1-5之间的整数，1最低，5最高
    TeamScheduleNode* next; // 指向下一个结点的指针
    // 构造函数，初始化属性
    TeamScheduleNode(string i,string n,string d, string t, string c, int p);

};

