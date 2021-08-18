#include "schedule.h"

LeagueSchedule::LeagueSchedule(std::vector<std::string> teams)
{
	// create matchdays
}

matchday LeagueSchedule::playMatchday()
{
	if (!isCompleted()) {
		auto not_completed{ [](const auto & matchday) { return !matchday.is_completed; } };
		auto curr_matchday{ std::find_if(matchdays.begin(), matchdays.end(), not_completed) };

		for (auto & match : curr_matchday->matches) {
			cout << "Match: " << match.team1 << " : " << match.team2 << endl;
			cout << "Score: ";
			cin >> match.score1;
			cin >> match.score2;
			cout << endl;
		}
		curr_matchday->is_completed = true;
		return *curr_matchday;
	}
	return matchday();
}

bool LeagueSchedule::isCompleted() const
{
	auto not_completed{ [](const auto & matchday) { return !matchday.is_completed; } };
	const auto iter{ std::find_if(matchdays.rbegin(), matchdays.rend(), not_completed) };
	if (iter != matchdays.crend()) return false;
}
