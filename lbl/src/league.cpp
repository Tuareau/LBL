#include "league.h"

void League::set() {
	Tournament::set();
	legs = 2; // INPUT 
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

	this->schedule = new LeagueSchedule(this->teams, this->legs);
	this->table = new LeagueTable(this->teams);
}

void League::runMatchday() {
	const MatchDay & curr_mday{ schedule->playMatchday() };
	table->handleMatchday(curr_mday);
	if (schedule->isCompleted())
		Tournament::set_actual(false);
}

void League::showSchedule() const
{
	schedule->draw();
}

void League::showTable() const
{
	table->draw();
}