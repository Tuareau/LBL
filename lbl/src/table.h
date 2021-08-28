#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "matchday.h"
#include "team.h"
#include "tableposition.h"

using namespace std;

class Table
{
public:
	Table() = default;
	Table(const Table &) = delete;
	virtual ~Table() {}

	virtual void handleMatchday(const MatchDay &) = 0;
	virtual void draw() const = 0;
};

class TablePosition;

class LeagueTable : public Table
{
private:
	vector<TablePosition> _table;

	void rewritePositions();
public:
	LeagueTable() = delete;
	LeagueTable(const Table &) = delete;
	virtual ~LeagueTable() {}

	explicit LeagueTable(const vector<string> &);

	void handleMatchday(const MatchDay &) override;
	virtual void draw() const override;
};