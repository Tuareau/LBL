#include "tournament.h"

Tournament::Tournament(const tournament_info & ti, shared_ptr<Season> & season)
{
	this->information.name = ti.name;
	this->information.participants = ti.participants;
	this->information.foundation_year = ti.foundation_year;
	this->information.tournament_type = ti.tournament_type;

	this->season = season;
}