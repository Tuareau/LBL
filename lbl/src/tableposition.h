#pragma once

#include <utility>

#include "team.h"

class TablePosition {
private:
	team_info _team;
	pos_info _pos;

public:
	TablePosition() = delete;
	TablePosition(const TablePosition &) = default;
	~TablePosition() {}

	explicit TablePosition(const tuple<string, string, size_t> &);

	size_t points() const;
	string name() const;
	void rewritePosition(size_t new_pos);

	void draw() const;

	enum class game_result { WIN, DEFEAT, DRAW };
	void addMatchResult(game_result, size_t, size_t);
};
