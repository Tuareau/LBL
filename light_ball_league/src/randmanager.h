#pragma once

#include "randstrategy.h"
class Schedule;

class RandManager
{
private:
	RandStrategy * randomizer;

public:
	RandManager() = delete;
	RandManager(const RandManager &) = delete;
	~RandManager() { }// delete RandStrategy; }

	explicit RandManager(RandStrategy * rand_strategy)
		: randomizer(rand_strategy) {}

	Schedule createSchedule(std::vector<string> & teams);
};