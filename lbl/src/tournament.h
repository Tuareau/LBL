#pragma once

#include <string>

using namespace std;

#include "season.h"

enum class tournament_type { LEAGUE, GROUP, ELIMINATION };

struct tournament_info {
	string name;
	int participants;
	tournament_type ttype;
	bool is_actual;
};

class Season;

class Tournament
{
private:
	tournament_info _information;
	Season * _season;

protected:
	void setActual(bool);

public:
	Tournament() = delete;
	virtual ~Tournament() {}

	explicit Tournament(Season * season);

	const string name() const;
	const tournament_type type() const;
	const size_t participants() const;
	bool isActual() const;

	virtual void set() = 0;
	virtual void fill() = 0;
	virtual void init() = 0;

	virtual void runMatchday() = 0;
};