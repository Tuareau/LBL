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
		default_name = sstr.str();
		this->teams.push_back(default_name);
		sstr.str(std::string());
		default_name.clear();
	}
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

	if (!shedule->isCompleted()) {
		const MatchDay & curr_mday{ shedule->playMatchday() };
		table->handleMatchday(curr_mday);
	}
	else {
		Tournament::set_actual(false);
	}
}

void League::showSchedule() const
{
	shedule->draw();
}

void League::showTable() const
{
	table->draw();
}


