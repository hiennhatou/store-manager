#include<iostream>
using namespace std;
#include "struct.h"

void entranceMenu(Store* store) {
	system("cls");
	int choice = 0;
	cout << "\n       *-------------------------------------------------*";
	cout << "\n       *   VUI LONG CHON YEU CAU CAN THUC HIEN           *";
	cout << "\n       *      1. Nhap don hang                           *";
	cout << "\n       *      2. Xem san pham trong kho                  *";
	cout << "\n       *      3. Xuat kho                                *";
	cout << "\n       *      4. Thoat                                   *";
	cout << "\n       *-------------------------------------------------*";

	while (choice > 4 || choice < 1) {
		cout << "\nNhap lua chon cua ban: ";
		cin >> choice;
	}
}