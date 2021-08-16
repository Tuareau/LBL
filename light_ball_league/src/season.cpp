#include "season.h"

Season::Season(const size_t & init_year, const time_of_year init_season) {
	this->initial_time_of_year = init_season;
	this->curr_season = init_season;
	this->initial_year = init_year;
	this->curr_year = init_year;
}

const string Season::name() const {
	stringstream sstream;
	sstream << curr_year;
	string year_str{ sstream.str() };

	if (curr_season == time_of_year::WINTER)
		return { "Winter " + year_str };
	if (curr_season == time_of_year::SPRING)
		return { "Spring " + year_str };
	if (curr_season == time_of_year::SUMMER)
		return { "Summer " + year_str };
	if (curr_season == time_of_year::AUTUMN)
		return { "Autumn " + year_str };
}

void Season::set() {
	// INPUT
}

void Season::addTournament(shared_ptr<Tournament> t) {
	tournaments.emplace_back(t);
}

void Season::deleteTournament(shared_ptr<Tournament> t) {
	auto del{ remove_if(begin(tournaments), end(tournaments),
		[&t](auto & x) { return t->name() == x->name(); }) };
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
		if (t->is_actual())
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



