#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "tournament.h"

using namespace std;

enum class time_of_year { WINTER, SPRING, SUMMER, AUTUMN };

class Season
{
private:
	static size_t initial_year;
	time_of_year season;
	size_t year;

	vector<shared_ptr<Tournament>> tournaments;

	// goToNextSeason()
	// areTournamentsClosed()
	// addTournament()

public:
	Season() = delete;
	Season(const Season &) = delete;
	Season(Season &&) = delete;

	Season(const size_t & year) {
		this->season = time_of_year::WINTER;
		this->initial_year = year;
		this->year = year;
	}

	const string name() const {
		stringstream sstream;
		sstream << year;
		string year_str{ sstream.str() };

		if (season == time_of_year::WINTER)
			return { "Winter " + year_str };
		if (season == time_of_year::SPRING)
			return { "Spring " + year_str };
		if (season == time_of_year::SUMMER)
			return { "Summer " + year_str };
		if (season == time_of_year::AUTUMN)
			return { "Autumn " + year_str };
	}

	void set() {
		// INPUT
	}

};

