#include <iostream>
#include <string>
#include <functional>
using namespace std;

#include "struct.h"
#include "array-handler.h"

void editModel(Model* models, unsigned int size) {
	string id;
	int position;
	int choice = 0;

	cout << "Nhap ma code cua model can xoa: ";
	getline(cin, id);
	position = ArrayHandler::find(models, size, [id](Model model) {
		return model.id == id;
	});

	if (position < 0 || position >= size) {
		cout << "Khong tim thay model\n";
		return;
	}
	
	system("cls");
	
	while (true) {
		cout << "...................Trang thai hien tai cua model...................\n";
		cout << "Name: " << models[position].name << endl;
		cout << "Price: " << models[position].price << endl;
		cout << "Quantity: " << models[position].quantity << endl;
		cout << "...................................................................\n";
		cout << "----------- Lua chon chinh sua -----------\n";
		cout << "1. Chinh sua name                         \n";
		cout << "2. Chinh sua price                        \n";
		cout << "3. Chinh sua quantity                     \n";
		cout << "4. Thoat                                  \n";
		while (choice < 1 || choice > 4) {
			cout << "Lua chon cua ban: ";
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "...................................................................\n";

		switch (choice) {
			case 1:
				cout << "Nhap name: ";
				getline(cin, models->name);
				break;
			case 2:
				cout << "Nhap price: ";
				cin >> models->price;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 3:
				cout << "Nhap quantity: ";
				cin >> models->quantity;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			case 4:
				return;
				break;
		}

		system("cls");
		choice = 0;
	}

}

void editModelMenu(Store* store) {
	string a = "";
	while (a != "MAC_PRODUCT" && a != "IPHONE_PRODUCT") {
		cout << "Nhap ma code cua dong san pham (\"MAC_PRODUCT\" hoac \"IPHONE_PRODUCT\"): ";
		getline(cin, a);
	}

	if (a == "MAC_PRODUCT") {
		editModel(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size);
	}
	else {
		editModel(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size);
	}
	system("cls");
}