#pragma once

#include "tournament.h"
#include "team.h"
#include "table.h"

#include <string>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

class Shedule;
class RandManager;

class League : public Tournament
{
private:
	vector<string> teams;
	Table * table;
	Shedule * shedule;
	RandManager * randomizer;

public:
	League() = delete;
	League(const League &) = delete;
	virtual ~League() {};

	explicit League(weak_ptr<Season> & season) : Tournament(season) {}

	void set() override;
	void fill() override;
	void init() override;
	void run() override;

};

// class Team (in list) or string
// class RandManager (maybe in shedule)
// class Shedule
// class MatchDay (in Shedule)
// class Table 
// class TablePos (in table)

// set -> fill -> init (rand + matchdays + table) -> (shedule <-run-> table) 

/*
set:
	participants
	name (valid)
	type (+legs if LEAGUE)
*/

/*
fill:
	all teams names (valid)
	if ok set_actual()
*/

/*
init:
	make random matchdays
	fill matchdays
	init table
*/

/*
shedule + table:
	make dependency 
	shedule runs matchdays and sends changes to the table
*/
