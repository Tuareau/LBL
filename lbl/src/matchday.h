#pragma once

#include <utility>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

#define POINTS_PER_WIN 3
#define POINTS_PER_DRAW 1

using namespace std;

using match = tuple<string, size_t, string, size_t>;

class MatchDay
{
private:
	vector<match> matches;
	bool is_completed;

public:
	MatchDay() : is_completed(true) {}
	MatchDay(const MatchDay &) = delete;
	~MatchDay() {}

	explicit MatchDay(size_t matches_count) {
		matches.reserve(matches_count);
		is_completed = false;
	}

	void addMatch(match & m) {
		matches.push_back(m);
	}

	void shuffleMatches() {
		random_device rd;
		mt19937 g(rd());
		shuffle(begin(matches), end(matches), g);
	}

	bool isCompleted() const {
		return is_completed;
	}

	bool isEmpty() const {
		return matches.empty();
	}

	void play() {
		for (auto & m : matches) {
			auto & [team1, score1, team2, score2] = m;
			cout << "Match: " << team1 << " : " << team2 << endl;
			cout << "Score: ";
			cin >> score1;
			cin >> score2;
			cout << endl;
		}
		is_completed = true;
	}

	const vector<match> & getMatches() const {
		return matches;
	}

};
