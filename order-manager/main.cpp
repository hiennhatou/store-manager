#include <iostream>
#include <string>
#include <csignal>
using namespace std;

#include "struct.h"

Store* dataLoading();
int entranceMenu();
void exitProcess(Store* store);
void read(Store* store);
void addProductMenu(Store* store);

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
				addProductMenu(store);
				break;
			case 2:
				read(store);
				break;
			case 4:
				exitProcess(store);
				break;
			default:
				break;
		}
	}

	return 0;
}
