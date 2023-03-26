#include<iostream>
#include<string>
using namespace std;
#include "struct.h"
#include "string-handler.h"

int entranceMenu() {
	string choiceStr = "";
	int choice;

	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON YEU CAU CAN THUC HIEN           *";
	cout << "\n       *      1. Xem san pham trong kho                  *";
	cout << "\n       *      2. Nhap model                              *";
	cout << "\n       *      3. Chinh sua model                         *";
	cout << "\n       *      4. Xoa model                               *";
	cout << "\n       *      5. Tim kiem model                          *";
	cout << "\n       *      6. Luu & Thoat                             *";
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
		if (choice < 1 || choice > 6) continue;
		break;
	}

	system("cls");
	return choice;
}
