/*
 *	ts.cpp
 *
 *  Created on: 18th of September 2024
 *      Author: jole
 *
 *      Driver program for testing timestamp-class
 *
 *
 *
 */

// Needed for getopt
#include <iostream>
#include <getopt.h>
//******************

#include <iostream>
#include <iomanip>
//#include <locale.h>
#include <time.h>
#include <sys/time.h>

#include "timestamp.h"


void parseOptarg(char **_optarg);
void getSystemDate(int &_year, short &_month, float &_day, bool _verbose);
void getSystemTime(short &_hour, short &_minute, float &_second, bool _verbose);
void printDate(int _year, short _month, float _day);
void printTime(short _hour, short _minute, float _second);



// driver code
int main(int argc, char *argv[])
{
	int		year;

	short	month;
	short	hour;
	short	minute;
	short	tz;
	short	dst;

	float	day;
	float	second;

	//double	lat = 64.6806799;	// oppi Leite
	//double	lon	= -11.2914454;	// oppi Leite

	//double	lat = 78.916663;	// Ny-Ålesund
	//double	lon	= 11.9333296;	// Ny-Ålesund

	bool	dateSupplied	= false;
	bool	timeSupplied	= false;
	bool	verbose			= false;

	//std::string	planet = "Earth";

	//
	//	getopt variables
	//
	int		c, optionIndex;


	//	TODO Add proper switches as the projects goes along
	char	*shortOptions = (char*)"d:p:t:vh";
	struct option	longOptions[] = {

					{"date",	required_argument,	NULL,	'd'},
					{"time",	required_argument,	NULL,	't'},
					{"planet",	required_argument,	NULL,	'p'},
					{"verbose",	no_argument,		NULL,	'v'},
					{"help",	no_argument,		NULL,	'h'},
					{"tz",		required_argument,	NULL,	1},
					//{"dow",		no_argument,		NULL,	'd'},
					{"lat",		required_argument,	NULL,	2},
					{"lon",		required_argument,	NULL,	3},
					{"dst",		required_argument,	NULL,	4},
					//
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	tz	= 0;
	dst	= 0;

	//
	//	getopt() switch statement
	//
	//	TODO Implement a proper help-screen for the user
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 1:		{
							//tz = atoi(optarg);
							break;
						}
			case 2:		{
							//lat = atof(optarg);
							break;
						}
			case 3:		{
							//lon = atof(optarg);
							break;
						}
			case 4:		{
							//dst = atoi(optarg);
							break;
						}
			case 'v':	{
							verbose	= true;
							//std::cout << "Verbose..." << (int)verbose << std::endl;
							break;
						}
			case 'd':	{
							//std::cout << "optarg: " << optarg << std::endl;
							year	= atoi(optarg);
							parseOptarg(&optarg);
							month	= atoi(optarg);
							parseOptarg(&optarg);
							day		= atof(optarg);
							dateSupplied = true;
							//std::cout << " year: " << year << std::endl;
							//std::cout << "month: " << month << std::endl;
							//std::cout << "  day: " << day << std::endl;


							break;
						}
			case 'p':	{
							//planet = optarg;
							break;
						}
			case 't':	{
							hour = atoi(optarg);
							parseOptarg(&optarg);
							minute = atoi(optarg);
							parseOptarg(&optarg);
							second = atof(optarg);
							// end of parsing optarg
							timeSupplied = true;

							break;
						}

			case 'h':	{
							//PrintUsage();
							exit(1);
						}
			default:	{
							std::cout << "Switch default - Je ne sais quoi" << std::endl;
							break;
						}
		} // switch(c)
	} // while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1)

	//dateSupplied ? printDate(year, month, day)		: getSystemDate(year, month, day, verbose);
	//timeSupplied ? printTime(hour, minute, second)	: getSystemTime(hour, minute, second, verbose);


	//std::string planet = "Earth";

	//sunpos * sp = new sunpos(year, month, day, hour, minute, second, tz, dst, verbose, planet, lat, lon);

	//sp->sp_printToScreen();

	//if(sp)
	//	delete sp;

	return 0;
}	//	int main(int argc, char *argv[])



void parseOptarg(char **_optarg)
{
	// removed '-' as delimiter for date, must allow for negative years
	//
	//while(**_optarg != '.' && **_optarg != '-' && **_optarg != '/' && **_optarg != ':'){
	while(**_optarg != '.' && **_optarg != '/' && **_optarg != ':'){
		(*_optarg)++;
	}
	(*_optarg)++;
	return;
}



void getSystemDate(int &_year, short &_month, float &_day, bool _verbose)
{
	//if(_verbose)
		std::cout << "Date not supplied, using system date..." << std::endl;

	time_t current = time(NULL);
	struct tm* current_s = localtime(&current);

	_day	= current_s->tm_mday;
	_month	= ++current_s->tm_mon;
	_year	= 1900 + current_s->tm_year;

	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	//cout.setf(ios::fixed);
	if(_verbose){
		printDate(_year, _month, _day);
	}

	return;
}


void getSystemTime(short &_hour, short &_minute, float &_second, bool _verbose)
{
	//if(_verbose)
		//std::cout << "Time not supplied, defaults to 12:00:00, which historically is when the next julian day begins." << std::endl;
		std::cout << "Time not supplied, using system time." << std::endl;

	time_t current = time(NULL);
	struct tm* current_s = localtime(&current);

	_hour	= current_s->tm_hour;
	_minute	= current_s->tm_min;
	_second	= current_s->tm_sec;

	//_hour	= 12;
	//_minute	= 0;
	//_second	= 0.000;


	if(_verbose){
		printTime(_hour, _minute, _second);
	}

	return;
}



void printDate(int _year, short _month, float _day)
{
	std::cout	<< "Date: " <<  _year
				<< "-" << std::setw(2) << std::setfill('0')<< _month
				<< "-" << std::setw(2) << std::setfill('0') << _day
				<< std::endl;
}



void printTime(short _hour, short _minute, float _second)
{
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	//std::cout.setf(std::ios::fixed);

	std::cout	<< "Time: " << std::setw(2) << std::setfill('0') << _hour
				<< ":" << std::setw(2) << std::setfill('0') << _minute
				<< ":" << std::setw(2) << std::setprecision(7) << _second
				<< std::endl;
}



