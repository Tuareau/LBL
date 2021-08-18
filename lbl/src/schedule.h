#pragma once

#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "table.h"

class Schedule
{
private:
	Table * table;

public:
	virtual ~Schedule() {}

	virtual matchday playMatchday() = 0;
	virtual bool isCompleted() const = 0;
};

class LeagueSchedule : public Schedule
{
private:
	std::vector<matchday> matchdays;

public:
	LeagueSchedule() = delete;
	LeagueSchedule(const LeagueSchedule &) = delete;
	virtual ~LeagueSchedule() {}

	explicit LeagueSchedule(std::vector<std::string>);

	virtual matchday playMatchday();
	virtual bool isCompleted() const;
};

struct matchday {
	vector<match> matches;
	bool is_completed;
};

struct match {
	string team1;
	size_t score1;
	string team2;
	size_t score2;
};
