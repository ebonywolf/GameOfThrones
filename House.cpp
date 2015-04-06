#include "House.h"
using namespace std;
/*
House::House ( string name = "", short power = 0, short supply = 0, short keeps = 0,
               list<Territory*> territories = list<Territory*>(), list<Unit*> units = list<Unit*>() )

	: name ( name ),
	power ( power ),
	supply ( supply ),
	keeps ( keeps ),
	generals ( generals ),
	territories ( territories ),
	units ( units )
{}
*/




House::~House()
{
	//dtor
}
bool House::operator< ( House& e ) {
	return this->position_IronThrone < e.position_IronThrone;

}
