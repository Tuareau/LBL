#include "table.h"

TablePosition::TablePosition(const std::tuple<string, string, size_t> & info) {
	team.division = get<0>(info);
	team.name = get<1>(info);
	pos.position = get<2>(info);
	pos.points = 0;
	team.goals = { 0,0,0 };
	team.games = { 0,0,0 };
}

LeagueTable::LeagueTable(std::vector<std::string> & teams)
{
	auto n = teams.size();
	auto i = 0;
	table.reserve(n);
	for (auto & team : teams) {
		auto info{ make_tuple(string("division"), team, ++i) };
		table.emplace_back(info);
	}
}

void LeagueTable::handleMatchday(const MatchDay & mday)
{
	auto result {
		[](const auto & lhs, const auto & rhs) {
			if (lhs > rhs) return TablePosition::game_result::WIN;
			if (lhs == rhs) return TablePosition::game_result::DRAW;
			if (lhs < rhs) return TablePosition::game_result::DEFEAT;
		}
	};

	for (const auto & m : mday.getMatches()) {
		const auto & [team1, score1, team2, score2] = m;

		auto pos1 { find_if(table.begin(), table.end(), 
			[&team1](const auto & pos) { return pos.name() == team1; })
		};
		auto pos2{ find_if(table.begin(), table.end(),
			[&team2](const auto & pos) { return pos.name() == team2; })
		};

		pos1->addMatchResult(result(score1, score2), score1, score2);
		pos2->addMatchResult(result(score2, score1), score2, score1);
	}

	sort(table.begin(), table.end(), 
		[](const auto & lhs, const auto & rhs) {return lhs.points() > rhs.points(); });

	rewritePositions();
}

void LeagueTable::rewritePositions()
{
	auto n = size_t(0);
	for (auto & pos : table)
		pos.rewritePosition(++n);
}

void TablePosition::addMatchResult(game_result res, size_t scored, size_t missed)
{
	this->team.goals.scored += scored;
	this->team.goals.missed += missed;
	this->team.goals.diff += scored - missed;

	if (res == game_result::WIN) {
		this->team.games.wins++;
		this->pos.points += POINTS_PER_WIN;
	}
	else if (res == game_result::DRAW) {
		this->team.games.draws++;
		this->pos.points += POINTS_PER_DRAW;
	}
	else this->team.games.defeats++;
}

void LeagueTable::draw() const
{
	cout << setw(37) << "\nLEAGUE TABLE\n";
	cout << setw(3) << "#" << setw(10) << "TEAM";
	cout << setw(3) << "W" << setw(3) << "L" << setw(3) << "D";
	cout << setw(3) << "GS" << setw(3) << "GM" << setw(3) << "DF" << setw(3) << "PT" << endl;

	for (const auto & pos : table) pos.draw();
}

void TablePosition::draw() const
{
	cout << setw(3) << pos.position << setw(10) << team.name;
	cout << setw(3) << team.games.wins << setw(3) 
		<< team.games.draws << setw(3) << team.games.defeats;
	cout << setw(3) << team.goals.scored << setw(3) << team.goals.missed 
		<< setw(3) << team.goals.diff << setw(3) << pos.points << endl;
}
