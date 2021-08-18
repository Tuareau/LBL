#include "league.h"

#include <sstream>

void League::set() {
	Tournament::set();
}

void League::fill() {
	const auto n{ Tournament::participants() };
	this->teams.reserve(n);

	stringstream sstr;
	string default_name;
	for (auto i = size_t(0); i < n; i++) { // INPUT
		sstr << "Team #" << i + 1;
		sstr >> default_name;
		this->teams.push_back(default_name);
		sstr.clear();
		default_name.clear();
	}

	Tournament::set_actual();
}

void League::init() {

	// rand
	RandStrategy * league_scheduler = new LeagueRandomizer;

	this->randomizer = new RandManager(league_scheduler);

	// shedule
	this->shedule = this->randomizer->createSchedule(this->teams);

	// table
	this->table = new Table(this->participants());
}

void League::run() {
	// play next matchday
	// shedule.playNext();

	// syncronize the table
	// shedule.sendToTable();
}
