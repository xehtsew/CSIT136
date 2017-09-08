#include "dateType.h"

int dateType::dom[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

dateType::dateType()
{
	setDate(1, 1, 1900);
}
dateType::dateType(int new_month, int new_day, int new_year)
{
	setDate(new_month, new_day, new_year);
}