#pragma once
#include <iostream>
#include <chrono>
using namespace std;
// 定义一个日期类，包含年月日属性
class Date
{
public:
	int year, month, day;
	// 构造函数，初始化日期
	Date(int y, int m, int d);
	tm to_tm();
	
};
