#include <iostream>
#include <string>
using namespace std;

#include "struct.h"

int readMenu() {
	int a = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON YEU CAU CAN THUC HIEN           *";
	cout << "\n       *      1. MACBOOK PRODUCT                         *";
	cout << "\n       *      2. IPHONE PRODUCT                          *";
	cout << "\n       *      3. TAT CA SAN PHAM                         *";
	cout << "\n       *-------------------------------------------------*";
	while (a < 1 || a > 3) {
		cout << "\n   Nhap lua chon: ";
		cin >> a;
	}
	system("cls");

	return a;
}

void readProductLine(PruductLine productLine) {
	cout << "Tong san pham: " << productLine.size << endl;
	for (int i = 0; i < productLine.size; i++) {
		cout << "............... Product " << i+1 << " ...............\n";
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
			system("pause");
			break;
		case 2:
			readProductLine(store->IPHONE_PRODUCT);
			system("pause");
			break;
		case 3:
			cout << "========================== MAC PRODUCT ==========================\n";
			readProductLine(store->MAC_PRODUCT);
			cout << "======================== IPHONE PRODUCT =========================\n";
			readProductLine(store->IPHONE_PRODUCT);
			system("pause");
			break;
	}
}