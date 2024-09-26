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
	std::string	retVal		= "";
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

	retVal = std::to_string((int)ts_day);
	retVal.append(dayPostFix);
	retVal.append(" of ");
	retVal.append(ts_getMonthName());
	retVal.append(" ");
	retVal.append(std::to_string((int)ts_year));

	return retVal;
}
