#pragma once
#include <iostream>
#include <string>
#include <regex>
#include<stdexcept>
using namespace std;
// 定义一个日程结点类，包含日期，时间，内容，重要性等属性，以及指向下一个结点的指针
class PersonalScheduleNode 
{
public:
    string date; // 日期，格式为yyyy-mm-dd
    string time; // 时间，格式为hh:mm
    string content; // 内容
    int priority; // 重要性，1-5之间的整数，1最低，5最高
    PersonalScheduleNode* next; // 指向下一个结点的指针
    // 构造函数，初始化属性
    PersonalScheduleNode(string d,string t,string c,int p);
    
};
