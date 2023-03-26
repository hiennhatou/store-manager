#include <iostream>
#include <string>
using namespace std;

#include "struct.h"

Store* dataLoading();
int entranceMenu();
void exitProcess(Store* store);
void read(Store* store);
void addModelMenu(Store* store);
void rmModelMenu(Store* store);
void editModelMenu(Store* store);

int main()
{	
	/// config
	Store* store = dataLoading();
	srand((unsigned)time(NULL));
	/// end config

	while (true) {
		int choice;
		choice = entranceMenu();

		switch (choice) {
			case 1:
				read(store);
				break;
			case 2:
				addModelMenu(store);
				break;
			case 3:
				editModelMenu(store);
				break;
			case 4:
				rmModelMenu(store);
				break;
			case 5:
				exitProcess(store);
				break;
			default:
				break;
		}
	}

	return 0;
}
