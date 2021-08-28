#include "league.h"

void League::set() {
	Tournament::set();
	_legs = 2; // INPUT 
}

void League::fill() {
	const auto n { Tournament::participants() };
	_teams.reserve(n);

	stringstream sstr;
	for (auto i = size_t(0); i < n; i++) { // INPUT
		sstr << "Team #" << i + 1;
		_teams.emplace_back(sstr.str());
		sstr.str(string());
	}
}

void League::init() {
	_table = new LeagueTable(_teams);
	_schedule = new LeagueSchedule(_teams, _legs);
}

void League::runMatchday() {
	const MatchDay & curr_mday { _schedule->playMatchday() };
	_table->handleMatchday(curr_mday);
	if (_schedule->isCompleted())
		Tournament::setActual(false);
}

void League::showSchedule() const {
	_schedule->draw();
}

void League::showTable() const {
	_table->draw();
}