#pragma once

#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

#include "matchday.h"
#include "table.h"

using namespace std;

class Schedule
{
public:
	virtual ~Schedule() {}

	virtual const MatchDay & playMatchday() = 0;
	virtual bool isCompleted() const = 0;
};

class LeagueSchedule : public Schedule
{
private:
	vector<MatchDay> matchdays;

	void makeEmptyShedule(vector<string> &);
	void shuffleMatches();
public:
	LeagueSchedule() = delete;
	LeagueSchedule(const LeagueSchedule &) = delete;
	virtual ~LeagueSchedule() {}

	explicit LeagueSchedule(vector<string> &);

	virtual const MatchDay & playMatchday() override;
	virtual bool isCompleted() const override;
};
