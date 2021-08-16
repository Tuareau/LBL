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

	bool tournamentsClosed() const;

public:
	Season() = delete;
	Season(const Season &) = delete;
	Season(Season &&) = delete;

	Season(const size_t & init_year, const time_of_year init_season);

	const string name() const;

	void set();

	void goToNextSeason();

	void addTournament(shared_ptr<Tournament> t);
	void deleteTournament(shared_ptr<Tournament> t);

};