#include <iostream>
#include <string>
using namespace std;

#include "struct.h"
#include "string-handler.h"

int readMenu() {
	string choiceStr = "";
	int choice = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON DONG SAN PHAM                   *";
	cout << "\n       *      1. MACBOOK PRODUCT LINE                    *";
	cout << "\n       *      2. IPHONE PRODUCT LINE                     *";
	cout << "\n       *      3. TAT CA DONG SAN PHAM                    *";
	cout << "\n       *      4. Quay lai menu chinh                     *";
	cout << "\n       *-------------------------------------------------*\n";
	while (true) {
		cout << "Nhap lua chon cua ban: ";
		getline(cin, choiceStr);
		if (!StringHandler::isNumber(choiceStr)) continue;
		try {
			choice = stoi(choiceStr);
		}
		catch (...) {
			continue;
		}
		if (choice < 1 || choice > 4) continue;
		break;
	}

	system("cls");

	return choice;
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
		case 4:
			system("cls");
			return;
	}
	system("pause");
	system("cls");
}
