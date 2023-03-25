#include <iostream>
#include <string>
using namespace std;

#include "struct.h"

Store* dataLoading();
int entranceMenu();
void exitProcess(Store* store);
void read(Store* store);

int main()
{	
	while (true) {
		int choice;
		srand((unsigned)time(NULL));
		Store* store = dataLoading();
		choice = entranceMenu();

		switch (choice) {
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
