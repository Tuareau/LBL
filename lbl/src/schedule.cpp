#include "schedule.h"

template <typename T>
void move_from_end_at(std::vector<T> &v, typename std::vector<T>::iterator it);

LeagueSchedule::LeagueSchedule(std::vector<std::string> & teams)
{
	makeEmptyShedule(teams);
	shuffleMatches();
}

void LeagueSchedule::makeEmptyShedule(vector<string> & teams)
{
	if (teams.size() % 2 != 0) teams.emplace_back("#bye");
	const auto ROUNDS{ teams.size() - 1 };
	const auto MATCHES{ teams.size() / 2 };

	// round robin
	for (size_t i = 0; i < ROUNDS; ++i) {
		MatchDay mday(MATCHES);
		for (size_t curr = 0; curr < MATCHES; ++curr) {
			match m{ make_tuple(teams[curr], 0, teams[curr + MATCHES], 0) };
			mday.addMatch(m);
		}
		matchdays.push_back(mday);
		auto second_team{ next(begin(teams)) };
		move_from_end_at(teams, second_team);
	}
}

void LeagueSchedule::shuffleMatches()
{
	for (auto & x : matchdays)
		x.shuffleMatches();
}

template <typename T>
void move_from_end_at(std::vector<T> &v, typename std::vector<T>::iterator it)
{
	if (it != std::end(v)) {
		v.insert(it, std::move(v.back());
		v.pop_back();
	}
}

const MatchDay & LeagueSchedule::playMatchday()
{
	auto not_completed { 
		[](const auto & matchday) { return !matchday.isCompleted(); } 
	};
	auto curr_matchday { 
		std::find_if(matchdays.begin(), matchdays.end(), not_completed) 
	};

	if (curr_matchday != matchdays.end()) {
		curr_matchday->play();
		return *curr_matchday;
	}
	else return MatchDay();
}

bool LeagueSchedule::isCompleted() const
{
	for (const auto & m : matchdays)
		if (!m.isCompleted()) return false;
	return true;
}

void LeagueSchedule::draw() const
{
}
