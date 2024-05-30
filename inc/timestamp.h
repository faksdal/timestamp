

class timestamp{

	enum class weekdays{monday, tuesday, wednesday, thursday, friday, saturday, sunday};
	enum class calendar_types{proleptic_julian, julian, gregorian};

	int				year;

	short			month, hour, minute;

	float			day, second;

	bool			is_leap;

	weekdays		weekday;

	calendar_types	calendar_type;



public:

	timestamp(void);
	timestamp(int _year, short _month, float _day, short _hour, short _minute, float _second);

};
