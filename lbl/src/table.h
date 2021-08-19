#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "matchday.h"
#include "team.h"

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
	vector<TablePosition> table;

	void rewritePositions();
public:
	LeagueTable() = delete;
	LeagueTable(const Table &) = delete;
	virtual ~LeagueTable() {}

	explicit LeagueTable(std::vector<std::string> &);

	void handleMatchday(const MatchDay &) override;
	virtual void draw() const override;
};

struct pos_info {
	size_t points;
	size_t position;
};

class TablePosition {
private:
	team_info team;
	pos_info pos;

public:
	TablePosition() = delete;
	TablePosition(const TablePosition &) = default;
	~TablePosition() {}

	explicit TablePosition(const std::tuple<string, string, size_t> &);

	constexpr auto points() const {
		return pos.points;
	}
	auto name() const {
		return team.name;
	}
	void rewritePosition(size_t new_pos) {
		pos.position = new_pos;
	}

	void draw() const;

	enum class game_result { WIN, DEFEAT, DRAW };
	void addMatchResult(game_result, size_t, size_t);
};