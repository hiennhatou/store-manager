#include<iostream>
using namespace std;
#include "struct.h"

int entranceMenu() {
	int choice = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON YEU CAU CAN THUC HIEN           *";
	cout << "\n       *      1. Xem san pham trong kho                  *";
	cout << "\n       *      2. Nhap model                              *";
	cout << "\n       *      3. Chinh sua model                         *";
	cout << "\n       *      4. Xoa model                               *";
	cout << "\n       *      5. Thoat                                   *";
	cout << "\n       *-------------------------------------------------*";

	while (choice > 5 || choice < 1) {
		cout << "\nNhap lua chon cua ban: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("cls");
	return choice;
}