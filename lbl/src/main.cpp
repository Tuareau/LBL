#include <string>
#include <memory>
#include <iostream>

#include "season.h"
#include "league.h"

using namespace std;

int main()
{
	size_t init_year = 2016; // INPUT
	time_of_year init_season = time_of_year::SUMMER; // INPUT

	auto season = new Season(init_year, init_season);

	auto LBL = new League(season);
	LBL->set();
	LBL->fill();
	LBL->init();
	
	while (LBL->is_actual()) {
		cout << "\nChoice:\n";
		cout << "1 - Shedule:\n";
		cout << "2 - Table:\n";
		cout << "3 - Play:\n";
		cout << "4 - Quit\n";
		int c;
		cin >> c;

		system("cls");

		if (c == 1) {
			LBL->showSchedule();
		}
		if (c == 2) {
			LBL->showTable();
		}
		if (c == 3) {
			LBL->runMatchday();
		}
		if (c == 4) {
			break;
		}

	}
	return 0;
}