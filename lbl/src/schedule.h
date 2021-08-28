#pragma once

#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

#include "matchday.h"
#include "table.h"
#include "tools.h"

using namespace std;

class Schedule
{
private:
	bool _is_completed;
protected:
	virtual void setCompleted();

public:
	virtual ~Schedule() {}
	
	virtual bool isCompleted() const;
	virtual const MatchDay & playMatchday() = 0;
	virtual void draw() const = 0;
};

class LeagueSchedule : public Schedule
{
private:
	vector<MatchDay> _matchdays;
	size_t _actual_matchdays_num;
	size_t _legs;

	void setEmptyShedule(vector<string> &);
	void shuffleMatches();
public:
	LeagueSchedule() = delete;
	LeagueSchedule(const LeagueSchedule &) = delete;
	virtual ~LeagueSchedule() {}

	LeagueSchedule(vector<string> &, size_t);

	virtual const MatchDay & playMatchday() override;
	virtual void draw() const override;
};
