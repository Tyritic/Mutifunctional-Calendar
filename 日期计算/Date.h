#pragma once
#include <iostream>
#include <chrono>
using namespace std;
// ����һ�������࣬��������������
class Date
{
public:
	int year, month, day;
	// ���캯������ʼ������
	Date(int y, int m, int d);
	tm to_tm();
	
};
