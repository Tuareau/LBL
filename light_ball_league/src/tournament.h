#pragma once

#include <string>
#include <memory>

using namespace std;

#include "season.h"

enum class tournament_types { LEAGUE, GROUP, ELIMINATION };

struct tournament_info {
	string name;
	int participants;
	//int foundation_year; // problem: one for the same names
	tournament_types tournament_type;
	bool is_actual;
};

class Tournament
{
private:
	tournament_info information;
	weak_ptr<Season> season;

public:
	Tournament() = delete;
	Tournament(const Tournament &) = delete;
	virtual ~Tournament() {}

	explicit Tournament(weak_ptr<Season> & season) {
		this->season = season;
		this->season.lock()->addNewTournament(shared_ptr<Tournament>(this));
		this->set();
		this->information.is_actual = true;
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
		/*
		- participants number
		- type
		- rounds
		- other
		*/
	}

	virtual void fill() = 0;

	virtual bool is_actual() = 0 {
		return information.is_actual;
	}

	virtual void run() = 0 {
		// events
	}
};