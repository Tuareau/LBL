#include "matchday.h"

MatchDay::MatchDay(size_t matches_count) 
{
	matches.reserve(matches_count);
	is_completed = false;
}

void MatchDay::addMatch(match & m) 
{
	matches.push_back(m);
}

void MatchDay::shuffleMatches() 
{
	mt_shuffle(begin(matches), end(matches));
}

bool MatchDay::isCompleted() const 
{
	return is_completed;
}

bool MatchDay::isEmpty() const 
{
	return matches.empty();
}

void MatchDay::play() 
{
	for (auto & m : matches) {
		auto &[team1, score1, team2, score2] = m;
		cout << "Match: " << team1 << " : " << team2 << endl;
		cout << "Score: ";
		cin >> score1;
		cin >> score2;
		cout << endl;
	}
	is_completed = true;
}

const vector<match> & MatchDay::getMatches() const 
{
	return matches;
}