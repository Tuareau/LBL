#pragma once

#include "tournament.h"

class League : public Tournament
{
private:
	// unique_ptr<vector<shared_ptr<TablePosition>> teams_table;

public:
	League() = delete;
	League(const League &) = delete;
	League(League &&) = delete;

	virtual ~League() {};

	League()

	

};

