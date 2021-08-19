#pragma once

#include <string>

using namespace std;

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

struct team_info {
	string division;
	string name;
	game_stats games;
	goal_stats goals;
	// increased_team_info * addition;
};

struct increased_team_info {
	size_t trophies;
	double rating;
};

class Team
{
private:
	team_info info;

public:
	Team() = delete;
	Team(const Team &) = delete;
	~Team() = default;
};