#include<iostream>
using namespace std;
#include "struct.h"

int entranceMenu() {
	int choice = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON YEU CAU CAN THUC HIEN           *";
	cout << "\n       *      1. Nhap san pham trong kho                 *";
	cout << "\n       *      2. Xem san pham trong kho                  *";
	cout << "\n       *      3. Xuat kho                                *";
	cout << "\n       *      4. Thoat                                   *";
	cout << "\n       *-------------------------------------------------*";

	while (choice > 4 || choice < 1) {
		cout << "\nNhap lua chon cua ban: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("cls");
	return choice;
}