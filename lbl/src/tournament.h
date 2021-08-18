#pragma once

#include <string>
#include <memory>

using namespace std;

#include "season.h"

enum class tournament_type { LEAGUE, GROUP, ELIMINATION };

struct tournament_info {
	string name;
	int participants;
	tournament_type ttype;
	bool is_actual;
};

class Tournament
{
private:
	tournament_info information;
	weak_ptr<Season> season;

protected:
	void set_actual();

public:
	Tournament() = delete;
	Tournament(const Tournament &) = delete;
	virtual ~Tournament() {}

	explicit Tournament(weak_ptr<Season> & season);

	const string name() const;
	const tournament_type type() const;
	const size_t participants() const;
	bool is_actual() const;

	virtual void set() = 0;
	virtual void fill() = 0;
	virtual void init() = 0;
	virtual void run() = 0;
};