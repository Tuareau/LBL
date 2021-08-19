#pragma once

#include <memory>
#include <vector>
#include <string>

#include "schedule.h"

using namespace std;

class Table
{
public:
	Table() = default;
	Table(const Table &) = delete;
	virtual ~Table() {}

	virtual void handleMatchday(MatchDay &) = 0;
};

class LeagueTable : public Table
{
private:
	vector<TablePosition> table;

public:
	LeagueTable() = delete;
	LeagueTable(const Table &) = delete;
	virtual ~LeagueTable() {}

	explicit LeagueTable(std::vector<std::string>);

	void handleMatchday(MatchDay &) override;
};


class TablePosition {
private:
	table_pos_info pos;

public:
	TablePosition() = delete;
	TablePosition(const TablePosition &) = delete;
	~TablePosition() {}

	explicit TablePosition(std::tuple<string, string, size_t> &);

	const string name() const;
};

// enum class result { WIN, DEFEAT, DRAW };

struct table_pos_info {
	size_t position;
	string division;
	string team;
	game_stats games;
	goal_stats goals;
	size_t points;
};

struct game_stats {
	size_t wins;
	size_t defeats;
	size_t draws;
};

struct goal_stats {
	size_t scored;
	size_t missed;
	int diff;
};