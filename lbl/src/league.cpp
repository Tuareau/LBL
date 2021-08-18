#include "league.h"

#include <sstream>
#include <random>
#include <algorithm>

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

	this->shuffleTeams();
	this->shedule = new LeagueSchedule(this->teams);
	this->table = new LeagueTable(this->teams);
}

void League::shuffleTeams()
{
	random_device rd;
	mt19937 g(rd());
	shuffle(begin(teams), end(teams), g);
}

void League::runMatchday() {

	if (!this->shedule->isCompleted()) {
		matchday curr_mday{ this->shedule->playMatchday() };
		this->table->handleMatchday(curr_mday);
	}
	else {
		Tournament::set_actual(false);
	}
}
