#include "Date.h"

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

tm Date::to_tm()
{
    tm t = { 0 };
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    return t;
}




