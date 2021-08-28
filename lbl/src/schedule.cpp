#include "schedule.h"

bool Schedule::isCompleted() const {
	return _is_completed;
}

void Schedule::setCompleted() {
	_is_completed = true;
}

LeagueSchedule::LeagueSchedule(vector<string> & teams, size_t legs) {
	_legs = legs;
	this->setEmptyShedule(teams);
	// this->shuffleMatches();
}

void LeagueSchedule::setEmptyShedule(vector<string> & teams) {
	if (teams.size() % 2 != 0) 
		teams.emplace_back(BYE_TEAM);
	const auto ROUNDS_PER_LEG { (teams.size() - 1) };
	_actual_matchdays_num = ROUNDS_PER_LEG * _legs;
	const auto MATCHES_PER_LEG { teams.size() / 2 };

	for (size_t n = 0; n < _legs; ++n) {
		mt_shuffle(begin(teams), end(teams));
		for (size_t i = 0; i < ROUNDS_PER_LEG; ++i) {
			MatchDay mday(MATCHES_PER_LEG);
			for (size_t curr = 0; curr < MATCHES_PER_LEG; ++curr) {
				if (teams[curr] == BYE_TEAM || teams[curr + MATCHES_PER_LEG] == BYE_TEAM)
					continue;
				match m { make_tuple(teams[curr], 0, teams[curr + MATCHES_PER_LEG], 0) };
				mday.addMatch(m);
			}
			_matchdays.push_back(mday);
			auto second_team { next(begin(teams)) };
			move_from_end_at(teams, second_team);
		}
	}
}

void LeagueSchedule::shuffleMatches() {
	for (auto & x : _matchdays)
		x.shuffleMatches();
}

const MatchDay & LeagueSchedule::playMatchday() {
	auto not_completed { 
		[](const auto & matchday) { return !matchday.isCompleted(); } 
	};
	auto curr_matchday { 
		find_if(_matchdays.begin(), _matchdays.end(), not_completed) 
	};

	if (curr_matchday != _matchdays.end()) {
		curr_matchday->play();
		if (--_actual_matchdays_num == 0) 
			Schedule::setCompleted();
		return *curr_matchday;
	}
	else return *_matchdays.begin();
}

void LeagueSchedule::draw() const {
	auto i = size_t(0);	
	auto leg_counter = i;
	const auto MATCHDAYS_PER_LEG { _matchdays.size() / _legs };

	for (const auto & m : _matchdays) {
		if (!i || i % MATCHDAYS_PER_LEG == 0)
			cout << setw(15) << "\nLEG #" << ++leg_counter << endl;
		cout << setw(15) << "\nMATCHDAY #" << ++i << endl;
		const auto & matches { m.getMatches() };
		for (const auto & match : matches) {
			cout << setw(12) << get<0>(match);
			cout << setw(3) << get<1>(match);
			cout << setw(3) << " : ";
			cout << get<3>(match);
			cout << setw(12) << get<2>(match) << endl;
		}
	}
}
