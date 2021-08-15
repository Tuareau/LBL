#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>

#include "tournament.h"

using namespace std;

enum class time_of_year { WINTER, SPRING, SUMMER, AUTUMN };

class Season
{
private:
	static size_t initial_year;
	static time_of_year initial_time_of_year;
	time_of_year curr_season;
	size_t curr_year;

	vector<shared_ptr<Tournament>> tournaments;

	bool tournamentsClosed() const {
		if (tournaments.empty())
			return false; // maybe other action
		for (const auto & t : tournaments)
			if (t->is_actual())
				return false;
	}

public:
	Season() = delete;
	Season(const Season &) = delete;
	Season(Season &&) = delete;

	Season(const size_t & init_year, const time_of_year init_season) {
		this->initial_time_of_year = init_season;
		this->curr_season = init_season;
		this->initial_year = init_year;
		this->curr_year = init_year;
	}

	const string name() const {
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

	void set() {
		// INPUT
	}

	void goToNextSeason() {
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

	void addNewTournament(shared_ptr<Tournament> t) {
		tournaments.emplace_back(t);
	}

	void deleteTournament(shared_ptr<Tournament> t) {
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

};