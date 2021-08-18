#pragma once

class GroupRandomizer;
class EliminationRandomizer;

class RandStrategy
{
public:
	virtual ~RandStrategy() {}
	virtual void makeSchedule() = 0;
};

class LeagueRandomizer : public RandStrategy
{
public:
	virtual ~LeagueRandomizer();
	virtual void makeSchedule() override;
};

