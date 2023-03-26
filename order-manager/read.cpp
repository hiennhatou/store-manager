#include <iostream>
#include <string>
using namespace std;

#include "struct.h"

int readMenu() {
	int a = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON DONG SAN PHAM                   *";
	cout << "\n       *      1. MACBOOK PRODUCT LINE                    *";
	cout << "\n       *      2. IPHONE PRODUCT LINE                     *";
	cout << "\n       *      3. TAT CA DONG SAN PHAM                    *";
	cout << "\n       *-------------------------------------------------*";
	while (a < 1 || a > 3) {
		cout << "\n   Nhap lua chon: ";
		cin >> a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("cls");

	return a;
}

void readProductLine(PruductLine productLine) {
	cout << "Tong san pham: " << productLine.size << endl;
	for (int i = 0; i < productLine.size; i++) {
		cout << "............... Model " << i+1 << " ...............\n";
		cout << "Code: " << productLine.models[i].id << endl;
		cout << "Name: " << productLine.models[i].name << endl;
		cout << "Price: " << productLine.models[i].price << endl;
		cout << "Quantity: " << productLine.models[i].quantity << endl;
	}
	cout << "..........................................\n";
}

void read(Store* store) {
	int choice = readMenu();
	switch (choice) {
		case 1:
			readProductLine(store->MAC_PRODUCT);
			break;
		case 2:
			readProductLine(store->IPHONE_PRODUCT);
			break;
		case 3:
			cout << "======================== MAC PRODUCT LINE ========================\n";
			readProductLine(store->MAC_PRODUCT);
			cout << "====================== IPHONE PRODUCT LINE =======================\n";
			readProductLine(store->IPHONE_PRODUCT);
			break;
	}
	system("pause");
	system("cls");
}