/*
 * getDateString.cpp
 *
 *  Created on: 25 Sept 2024
 *      Author: jole
 *
 *	Formats and returns the date as a string object
 */

#include "timestamp.h"



std::string timestamp::ts_getDateString(void)
{
	std::string	retVal		= "date string";
	std::string	dayPostFix	= "th";

	switch((int)ts_day){
		case 1:		dayPostFix = "st";
					break;
		default:	break;
	}

	return retVal;
}
