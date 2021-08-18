#pragma once

#include "tournament.h"
#include "team.h"
#include "table.h"
#include "schedule.h"

#include <string>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

class League : public Tournament
{
private:
	vector<string> teams;
	Table * table;
	Schedule * shedule;

	void shuffleTeams();
public:
	League() = delete;
	League(const League &) = delete;
	virtual ~League() {};

	explicit League(weak_ptr<Season> & season) : Tournament(season) {}

	void set() override;
	void fill() override;
	void init() override;
	
	void runMatchday() override;

};