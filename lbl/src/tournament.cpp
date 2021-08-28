#include "tournament.h"

Tournament::Tournament(Season * season) {
	_season = season;
	_season->addTournament(this);
	this->set();
}

const string Tournament::name() const {
	return _information.name;
}

const tournament_type Tournament::type() const {
	return _information.ttype;
}

const size_t Tournament::participants() const {
	return _information.participants;
}

bool Tournament::isActual() const {
	return _information.is_actual;
}

void Tournament::setActual(bool is_actual) {
	_information.is_actual = is_actual;
}

void Tournament::set() { // INPUT
	_information.name = string{ "LBL" };
	_information.participants = 4;
	_information.ttype = tournament_type::LEAGUE;
	_information.is_actual = true;
}