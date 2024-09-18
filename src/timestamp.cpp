



#include <iostream>		// for cout
#include <stdlib.h>		// for exit()

#include "timestamp.h"



timestamp::timestamp(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, short _dst, bool _verbose)
{
	ts_validDate = true;

	ts_year 	= _year;
	ts_month	= _month;
	ts_hour		= _hour - _tz - _dst;
	ts_minute	= _minute;
	ts_day		= _day;
	ts_second	= _second;
	ts_tz		= _tz;
	ts_dst		= _dst;
	ts_verbose	= _verbose;

	/*
	std::cout << " _year: " << _year << std::endl;
	std::cout << "_month: " << _month << std::endl;
	std::cout << "  _day: " << _day << std::endl;

	std::cout << " ts_year: " << ts_year << std::endl;
	std::cout << "ts_month: " << ts_month << std::endl;
	std::cout << "  ts_day: " << ts_day << std::endl;
	*/

	ts_parseDate();


	// check date for validity
	// Check 31-day months first
	// TODO: Must allow for fraction of days, also last day of month.
	// TODO: This means we must allow for day > 31 (up til 32, but not including 32)
	//
	if(ts_month == 1 ||
	   ts_month == 3 ||
	   ts_month == 5 ||
	   ts_month == 7 ||
	   ts_month == 8 ||
	   ts_month == 10 ||
	   ts_month == 12){

		if(_day < 1 || _day > 31){
			ts_validDate = false;
		}
	}
	else if(ts_month == 4 ||
			ts_month == 6 ||
			ts_month == 9 ||
			ts_month == 11){

		if(_day < 1 || _day > 30){
			ts_validDate = false;
		}
	}
	else if(ts_month == 2 && ts_isLeap){

		if(_day < 1 || _day > 29){
			ts_validDate = false;
		}
	}
	else if(ts_month == 2 && !ts_isLeap){

		if(_day < 1 || _day > 28){
			ts_validDate = false;
		}
	}


	if(!ts_validDate){
		std::cerr << "[ ERROR ] Supply a valid date!" << std::endl;
		exit(-1);
	}

	return;
}




void timestamp::ts_parseDate(void)
{
	//	We assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statements
	ts_validDate		= true;
	ts_gregorianDate	= true;


	//	Default is no leap year
	ts_isLeap	= false;
	if(ts_year > 1582){
		if( ((ts_year % 4) == 0) && (((ts_year % 100) != 0) || ((ts_year % 400) == 0))){
			if(ts_verbose)
				std::cout << ts_year << " is a Leap year :-)" << std::endl;

			ts_isLeap	= true;
		}
		else{
			if(ts_verbose)
				std::cout << ts_year << " is not Leap year!" << std::endl;

			ts_isLeap	= false;
		}
	}


	//	If we're in 1582, check for valid date. There are ten missing dates this year as we went from
	//	using the Julian calendar to be using the Gregorian calendar.
	if(ts_year == 1582 && ts_month == 10){
		switch((int)ts_day){
		case 1:
		case 2:
		case 3:
		case 4:		ts_gregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	std::cout << std::endl << "No such date!\n Exiting..." << std::endl;
					ts_validDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(ts_year == 1582 && ts_month < 10){
		ts_gregorianDate = false;

		//if(ts_verbose)
			//std::cout << std::endl << "Year == 1582 and month is less than 10." << std::endl;
	}
	else if(ts_year < 1582){
		ts_gregorianDate = false;

		//if(ts_verbose)
			//std::cout << std::endl << "Year is less than 1582." << std::endl;
	}

	//calendar_types{proleptic_julian, julian, gregorian};

	if(ts_gregorianDate){
		ts_calendar_type = calendar_types::gregorian;
		//std::cout << "Gregorian " << (int)ts_calendar_type << std::endl;
	}

	else if(!ts_gregorianDate){
		//std::cout << "ts_year: " << ts_year << std::endl;
		if(ts_year >= -45){
			ts_calendar_type = calendar_types::julian;
			//std::cout << "Julian " << (int)ts_calendar_type << std::endl;
		}
		else if (ts_year < -45){
			ts_calendar_type = calendar_types::proleptic_julian;
			//std::cout << "Propleptic Julian " << (int)ts_calendar_type << std::endl;
		}
	}

	if(ts_verbose){
		switch(ts_calendar_type){
			case calendar_types::gregorian:			break;
			case calendar_types::julian:			break;
			case calendar_types::proleptic_julian:	break;
			default:								break;
		}

		std::cout << ts_getCalendarTypeString() << std::endl;

	} // switch(ts_calendar_type)

}



void timestamp::ts_calculateWeekday(void)
{
	//ts_weekday = weekdays::monday;
}



std::string timestamp::ts_getCalendarTypeString(void)
{
	//std::cout << "ts_calendar_type: " << (int)ts_calendar_type << std::endl;
	//std::cout << "calendar_type[0] " << calendar_type[0] << std::endl;
	//std::cout << "calendar_type[1] " << calendar_type[1] << std::endl;
	//std::cout << "calendar_type[2] " << calendar_type[2] << std::endl;

	//std::cout << "calendar_type[(int)ts_calendar_type] " << calendar_type[(int)ts_calendar_type] << std::endl;
	return calendar_type[(int)ts_calendar_type];
}





