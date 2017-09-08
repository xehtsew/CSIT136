#include "addressType.h"

addressType::addressType()
{
	setAddress("855 North Vermont Avenue", "Los Angeles", "California", "90029");
}
addressType::addressType(const string& new_streetAddress, const string& new_city, const string& new_state, const string& new_zipCode)
{
	setAddress(new_streetAddress, new_city, new_state, new_zipCode);
}