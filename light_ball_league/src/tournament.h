#pragma once

#include <string>
#include <memory>

using namespace std;

#include "season.h"

enum class tournament_types { LEAGUE, GROUP, ELIMINATION };

struct tournament_info {
	string name;
	int participants;
	//int foundation_year; ?
	tournament_types tournament_type;
	bool is_actual;
};

class Tournament
{
private:
	tournament_info information;
	weak_ptr<Season> season;

public:
	Tournament() {}
	Tournament(const Tournament &) = delete;
	virtual ~Tournament() {}

	explicit Tournament(weak_ptr<Season> & season) {
		this->season = season;
		// season.addTournament();
	}

	virtual const string name() const = 0 {
		return information.name;
	}

	virtual const tournament_info info() const = 0 {
		return information;
	}

	virtual const size_t participants() const = 0 {
		return information.participants;
	}

	virtual void set() = 0 {
		// INPUT
	}

};