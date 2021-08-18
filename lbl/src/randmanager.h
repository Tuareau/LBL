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

/*

#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(v.begin(), v.end(), g);

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}
*/