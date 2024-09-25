/*
 * getDateString.cpp
 *
 *  Created on: 25 Sept 2024
 *      Author: jole
 *
 *	Formats and returns the date as a string object
 */

#include <iostream>

#include "timestamp.h"



std::string timestamp::ts_getDateString(void)
{
	std::string	retVal		= "date string";
	std::string	dayPostFix	= "th";

	switch((int)ts_day){
		case 1:		dayPostFix = "st";
					break;
		case 2:		dayPostFix = "nd";
					break;
		case 3:		dayPostFix = "rd";
					break;
		case 21:	dayPostFix = "st";
					break;
		case 22:	dayPostFix = "nd";
					break;
		case 23:	dayPostFix = "rd";
					break;
		case 31:	dayPostFix = "st";
					break;
		default:	break;
	}

	//std::cout << (int)ts_day << std::endl;

	retVal = ts_day;
	std::cout << retVal << std::endl;

	retVal.append(dayPostFix);
	std::cout << retVal << std::endl;

	return retVal;
}
