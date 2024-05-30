

#include "timestamp.h"


timestamp::timestamp(int _year, short _month, float _day, short _hour, short _minute, float _second)
{
	year 	= _year;
	month	= _month;
	hour	= _hour;
	minute	= _minute;
	day		= _day;
	second	= _second;

	is_leap = false;
	return;
}
