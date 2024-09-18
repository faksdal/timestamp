
#ifndef INC_TIMESTAMP_H_
#define INC_TIMESTAMP_H_

#include <string>



class timestamp{

	enum class calendar_types{proleptic_julian, julian, gregorian};
	//std::string	calendar_type[3] = { "Proleptic Julian", "Julian", "Gregorian" };

	int				ts_year;

	short			ts_month, ts_hour, ts_minute, ts_tz, ts_dst;

	double			ts_day, ts_second;

	bool			ts_isLeap;
	bool			ts_validDate, ts_gregorianDate;
	bool			ts_verbose;

	calendar_types	ts_calendar_type;


	void	ts_parseDate(void);
	void	ts_calculateWeekday(void);

protected:
	std::string	month_name[12]		= { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	std::string	calendar_type[3]	= { "Proleptic Julian", "Julian", "Gregorian" };


public:

	timestamp(void);
	timestamp(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, short _dst, bool _verbose);

	/*************************************************************************/
	int		ts_getYear(void)			{return ts_year;}

	bool	ts_getLeap(void)			{return ts_isLeap;}
	bool	ts_getGregorianDate(void)	{return ts_gregorianDate;}

	short	ts_getMonth(void)			{return ts_month;}
	short	ts_getHour(void)			{return ts_hour;}
	short	ts_getMinute(void)			{return ts_minute;}

	double	ts_getDay(void)				{return ts_day;}
	double	ts_getSecond(void)			{return ts_second;}

	std::string	ts_getMonthName(void)			{return month_name[ts_month - 1];}

	calendar_types	ts_getCalendarType(void)	{return ts_calendar_type;}
	/*************************************************************************/

	std::string		ts_getCalendarTypeString(void);

};

#endif // INC_TIMESTAMP_H_
