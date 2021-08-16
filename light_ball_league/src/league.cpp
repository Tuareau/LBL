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
	// shedule
	// table
}

void League::run() {
	// play next matchday
	// syncronize the table
}
