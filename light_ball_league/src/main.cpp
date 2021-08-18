#include <string>
#include <memory>

#include "season.h"
#include "league.h"

using namespace std;

int main()
{
	// empty window

	// set initial season
	size_t init_year = 2016; // INPUT
	time_of_year init_season = time_of_year::SUMMER; // INPUT

	auto season = make_unique<Season>(init_year, init_season);

	// create tournament
	auto LBL = make_unique<League>(season);
	LBL->set();

	// create another

	// play tournament
	// make shedule
	// round: auto rand or input
	
	// all leagues completed:
	// add stats
	// jump season




	return 0;
}