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

	League(size_t participants) {
		
	}

	

};

