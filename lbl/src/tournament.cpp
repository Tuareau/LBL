#include "tournament.h"

Tournament::Tournament(weak_ptr<Season> & season) {
	this->season = season;
	this->season.lock()->addTournament(shared_ptr<Tournament>(this));
	this->set();
}

const string Tournament::name() const {
	return information.name;
}

const tournament_type Tournament::type() const {
	return information.ttype;
}

const size_t Tournament::participants() const {
	return information.participants;
}

bool Tournament::is_actual() const {
	return information.is_actual;
}

void Tournament::set_actual(bool is_actual) {
	information.is_actual = is_actual;
}

void Tournament::set() { // INPUT
	information.name = string{ "LBL" };
	information.participants = 8;
	information.ttype = tournament_type::LEAGUE;
	information.is_actual = true;
}