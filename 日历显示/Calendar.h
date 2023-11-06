#pragma once
#include<iostream>
#include<fstream>
class Calendar
{
private:
	int year;
	int month;
public:
	Calendar(int year = 2023, int month = 6);
	void showCalendar();//在控制台显示日历
};

