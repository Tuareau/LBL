#include "table.h"

LeagueTable::LeagueTable(const vector<string> & teams) {
	auto n = teams.size();
	auto i = 0;
	_table.reserve(n);
	for (auto & team : teams) {
		auto info { make_tuple(string("#division"), team, ++i) };
		_table.emplace_back(info);
	}
}

void LeagueTable::handleMatchday(const MatchDay & mday) {
	auto result {
		[](const auto & lhs, const auto & rhs) {
			if (lhs > rhs) return TablePosition::game_result::WIN;
			if (lhs == rhs) return TablePosition::game_result::DRAW;
			if (lhs < rhs) return TablePosition::game_result::DEFEAT;
		}
	};

	for (const auto & m : mday.getMatches()) {
		const auto & [team1, score1, team2, score2] = m;

		auto pos1 { find_if(_table.begin(), _table.end(), 
			[&team1](const auto & pos) { return pos.name() == team1; })
		};
		auto pos2 { find_if(_table.begin(), _table.end(),
			[&team2](const auto & pos) { return pos.name() == team2; })
		};

		pos1->addMatchResult(result(score1, score2), score1, score2);
		pos2->addMatchResult(result(score2, score1), score2, score1);
	}

	sort(_table.begin(), _table.end(), 
		[](const auto & lhs, const auto & rhs) { return lhs.points() > rhs.points(); } );

	this->rewritePositions();
}

void LeagueTable::rewritePositions() {
	auto n = size_t(0);
	for (auto & pos : _table) {
		if (pos.name() != BYE_TEAM)
			pos.rewritePosition(++n);
	}
}

void TablePosition::addMatchResult(game_result res, size_t scored, size_t missed) {
	_team.goals.scored += scored;
	_team.goals.missed += missed;
	_team.goals.diff += scored - missed;

	if (res == game_result::WIN) {
		_team.games.wins++;
		_pos.points += POINTS_PER_WIN;
	}
	else if (res == game_result::DRAW) {
		_team.games.draws++;
		_pos.points += POINTS_PER_DRAW;
	}
	else _team.games.defeats++;
}

void LeagueTable::draw() const {
	cout << setw(37) << "\nLEAGUE TABLE\n";
	cout << setw(4) << "#" << setw(10) << "TEAM";
	cout << setw(4) << "W" << setw(4) << "L" << setw(4) << "D";
	cout << setw(4) << "GS" << setw(4) << "GM" << setw(4) << "DF" << setw(4) << "PT" << endl;

	for (const auto & pos : _table) 
		if (pos.name() != BYE_TEAM) pos.draw();
}
