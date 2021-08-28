#include "matchday.h"

MatchDay::MatchDay(size_t matches_count) {
	_matches.reserve(matches_count);
	_is_completed = false;
}

void MatchDay::addMatch(match & m) {
	_matches.push_back(m);
}

void MatchDay::shuffleMatches() {
	mt_shuffle(begin(_matches), end(_matches));
}

bool MatchDay::isCompleted() const {
	return _is_completed;
}

bool MatchDay::isEmpty() const {
	return _matches.empty();
}

void MatchDay::play() {
	for (auto & m : _matches) {
		auto & [team1, score1, team2, score2] = m;
		cout << "Match: " << team1 << " : " << team2 << endl;
		cout << "Score: ";
		cin >> score1;
		cin >> score2;
		cout << endl;
	}
	_is_completed = true;
}

const vector<match> & MatchDay::getMatches() const {
	return _matches;
}