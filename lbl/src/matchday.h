#pragma once

#include <utility>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <iostream>

#include "tools.h"

#define POINTS_PER_WIN 3
#define POINTS_PER_DRAW 1
#define BYE_TEAM "#bye"

using namespace std;

using match = tuple<string, size_t, string, size_t>;

class MatchDay
{
private:
	vector<match> matches;
	bool is_completed;

public:
	MatchDay() : is_completed(true) {}
	MatchDay(const MatchDay &) = default;
	~MatchDay() {}

	explicit MatchDay(size_t matches_count);

	inline void addMatch(match & m);
	inline void shuffleMatches();
	inline const vector<match> & getMatches() const;

	inline bool isCompleted() const;
	inline bool isEmpty() const;

	void play();
};
