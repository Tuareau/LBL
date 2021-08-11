#pragma once

#include <string>
#include <memory>

using namespace std;

#include "season.h"

enum class tournament_types { LEAGUE, GROUP, ELIMINATION };

struct tournament_info {
	string name;
	int participants;
	int foundation_year;
	tournament_types tournament_type;
};

class Tournament
{
private:
	tournament_info information;
	shared_ptr<Season> season;

public:
	Tournament() = delete;
	Tournament(const Tournament &) = delete;
	Tournament(Tournament &&) = delete;

	virtual ~Tournament() {}

	Tournament(const tournament_info &, shared_ptr<Season> & season);

	virtual const string name() const = 0;
	virtual const tournament_info info() const = 0;

};