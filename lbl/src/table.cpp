#include "table.h"

TablePosition::TablePosition(std::tuple<string, string, size_t> & info) {
	pos.division = get<0>(info);
	pos.team = get<1>(info);
	pos.position = get<2>(info);
	pos.points = 0;
	pos.goals = { 0,0,0 };
	pos.games = { 0,0,0 };
}

LeagueTable::LeagueTable(std::vector<std::string> teams)
{
	auto n = teams.size();
	table.reserve(n);
	for (auto & team : teams) {
		auto info{ make_tuple(string("division"), team, n) };
		table.push_back(TablePosition(info));
		--n;
	}
}

void LeagueTable::handleMatchday(MatchDay & mday)
{

}
