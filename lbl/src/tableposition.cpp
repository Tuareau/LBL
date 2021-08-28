#include "tableposition.h"

#include <iostream>
#include <iomanip>

using namespace std;

TablePosition::TablePosition(const std::tuple<string, string, size_t> & info) {
	const auto & [division, team, position] = info;
	_team.division = division;
	_team.name = team;
	_pos.position = position;
	_pos.points = 0;
	_team.goals = { 0,0,0 };
	_team.games = { 0,0,0 };
}

size_t TablePosition::points() const {
	return _pos.points;
}
string TablePosition::name() const {
	return _team.name;
}
void TablePosition::rewritePosition(size_t new_pos) {
	_pos.position = new_pos;
}

void TablePosition::draw() const {
	cout << setw(4) << _pos.position << setw(10) << _team.name;
	cout << setw(4) << _team.games.wins << setw(4)
		<< _team.games.draws << setw(4) << _team.games.defeats;
	cout << setw(4) << _team.goals.scored << setw(4) << _team.goals.missed
		<< setw(4) << _team.goals.diff << setw(4) << _pos.points << endl;
}