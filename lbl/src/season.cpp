#include "season.h"

Season::Season(const size_t & init_year, const time_of_year init_season) {
	_initial_time_of_year = init_season;
	_curr_season = init_season;
	_initial_year = init_year;
	_curr_year = init_year;
}

const string Season::name() const {
	if (_curr_season == time_of_year::WINTER)
		return { "Winter " + _curr_year };
	if (_curr_season == time_of_year::SPRING)
		return { "Spring " + _curr_year };
	if (_curr_season == time_of_year::SUMMER)
		return { "Summer " + _curr_year };
	if (_curr_season == time_of_year::AUTUMN)
		return { "Autumn " + _curr_year };
}

void Season::set() {
	// INPUT
}

void Season::addTournament(Tournament * t) {
	tournaments.push_back(t);
}

void Season::deleteTournament(Tournament * t) {
	auto del { remove_if(begin(tournaments), end(tournaments),
		[&t](const auto & x) { return t->name() == x->name(); }) };
#ifndef OPTIMIZE
	tournaments.erase(del, end(tournaments));
#else
	if (del != end(tournaments)) {
		*del = move(tournaments.back());
		tournaments.pop_back();
	}
#endif	
}

bool Season::tournamentsClosed() const {
	if (tournaments.empty())
		return false; // maybe other action
	for (const auto & t : tournaments)
		if (t->isActual())
			return false;
}

void Season::goToNextSeason() {
	if (tournamentsClosed()) {
		/*
		- all tournaments go to file
		- increase year
		- add to seasons list
		*/
	}
	else {
		// continue this
	}
}



