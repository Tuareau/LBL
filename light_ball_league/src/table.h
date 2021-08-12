#pragma once

#include <memory>
#include <vector>
#include <string>

using namespace std;

class TablePosition;

class Table
{
private:
	unique_ptr<vector<TablePosition>> table;

public:
	Table() = delete;
	Table(const Table &) = delete;

	virtual ~Table() {}

	explicit Table(size_t participants) {

	}

	vector<string> participants() const {
		vector<string> teams;
		teams.reserve(table->size());
		for (const auto & team_pos : *table)
			teams.emplace_back(team_pos.name());
		return teams;
	}



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

struct table_pos_info {
	size_t position;
	string division;
	string team;
	game_stats games;
	goal_stats goals;
	size_t points;
};

class TablePosition {
private:
	table_pos_info pos;

public:
	TablePosition() = delete;
	TablePosition(const TablePosition &) = delete;

	~TablePosition() {}

	const string name() const {
		return { pos.team };
	}
	   	 	
};