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

		auto pos1{ find(table.begin(), table.end(), team1) };
		auto pos2{ find(table.begin(), table.end(), team2) };

		pos1->addMatchResult(result(score1, score2), score1, score2);
		pos2->addMatchResult(result(score2, score1), score2, score1);
	}

	sort(table.begin(), table.end(), 
		[](const auto & lhs, const auto & rhs) {return lhs.points() > rhs.points(); });
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
}
