#pragma once

#include "tournament.h"
#include "team.h"
#include "table.h"

#include <memory>
#include <vector>

using namespace std;

class League : public Tournament
{
private:
	unique_ptr<vector<Team>> teams;
	unique_ptr<Table> table;
	// unique_ptr<Shedule> shedule;
	// unique_ptr<RandManager> randomizer;

public:
	League() = delete;
	League(const League &) = delete;

	virtual ~League() {};

	League(weak_ptr<Season> & season) : Tournament(season) {}

	void set() override {
		Tournament::set();
		size_t participants{ Tournament::participants() };
		table = make_unique<Table>(participants);
		vector<string> teams_names = table->participants();
		teams = make_unique<vector<Team>>(teams_names);
	}

	

};

