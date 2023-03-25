#include <iostream>
#include <string>
using namespace std;

#include "struct.h"
#include "init.h"

void entranceMenu(Store *store);
void exitProcess(Store* store);

int main()
{	
	srand((unsigned)time(NULL));
	Store* store = dataLoading();
	entranceMenu(store);
	exitProcess(store);

	system("pause");
	return 0;
}
