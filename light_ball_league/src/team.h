#pragma once

#include <string>

using namespace std;

struct team_game_stats {
	size_t wins;
	size_t defeats;
	size_t draws;
};

struct team_goal_stats {
	size_t scored;
	size_t missed;
	int diff;
};

struct team_info {
	size_t trophies;
	string division;
	string team;
	team_game_stats games;
	team_goal_stats goals;
	double rating;
};

class Team
{
private:
	team_info info;

public:
	Team() = delete;
	Team(const Team &) = delete;

	~Team() {}

	const string name() const {
		return info.team;
	}
};