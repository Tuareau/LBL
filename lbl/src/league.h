#pragma once

#include "tournament.h"
#include "table.h"
#include "schedule.h"
#include "tools.h"

#include <string>
#include <sstream>
#include <vector>


using namespace std;

#define WIN_POINTS 3

class League : public Tournament
{
private:
	vector<string> teams;
	Table * table;
	Schedule * schedule;
	size_t legs;

public:
	League() = delete;
	League(const League &) = delete;
	virtual ~League() {};

	explicit League(Season * season) : Tournament(season) {}

	void set() override;
	void fill() override;
	void init() override;
	
	void runMatchday() override;
	void showSchedule() const;
	void showTable() const;

};