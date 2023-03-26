#include <iostream>
#include <string>
#include <functional>
using namespace std;

#include "struct.h"
#include "random.h"
#include "array-handler.h"
#include "string-handler.h"

Model generateModel() {
	Model model;
	string name;
	string quantity = "";
	string price = "";

	cout << "Nhap ten model: ";
	getline(cin, name);

	while (true) {
		cout << "Nhap gia: ";
		getline(cin, price);
		if (!StringHandler::isNumber(price)) continue;
		break;
	}

	while (true) {
		cout << "Nhap so luong: ";
		getline(cin, quantity);
		if (!StringHandler::isNumber(quantity)) continue;
		break;
	}

	model.id = random(10);
	model.name = name;
	model.quantity = quantity;
	model.price = price;
	return model;
}

void addModel(Store *store, int number) {
	for (int i = 0; i < number; i++) {
		string a;
		cout << "========= Them San Pham " << i + 1 << " =========\n";
		cout << "Nhap ma code cua dong san pham (\"MAC_PRODUCT\" hoac \"IPHONE_PRODUCT\" hoac nhap bat ky de thoat): ";
		getline(cin, a);
		if (a != "IPHONE_PRODUCT" && a != "MAC_PRODUCT") {
			system("cls");
			return;
		}
		cout << "---------\n";
		Model newModel = generateModel();

		if (a == "IPHONE_PRODUCT") {
			Model* temp = store->IPHONE_PRODUCT.models;
			store->IPHONE_PRODUCT.models = ArrayHandler::push(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size, newModel);
			delete[] temp;
			store->IPHONE_PRODUCT.size += 1;
		}
		else if (a == "MAC_PRODUCT") {
			Model* temp = store->MAC_PRODUCT.models;
			store->MAC_PRODUCT.models = ArrayHandler::push(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size, newModel);
			delete[] temp;
			store->MAC_PRODUCT.size += 1;
		}
	}
}

void addModelMenu(Store* store) {
	string numberOfInsertStr = "";
	int numberOfInsert = 0;

	while (true) {
		cout << "So model can nhap: ";
		getline(cin, numberOfInsertStr);
		if (!StringHandler::isNumber(numberOfInsertStr)) continue;
		try {
			numberOfInsert = stoi(numberOfInsertStr);
		}
		catch (...) {
			continue;
		}
		if (numberOfInsert <= 0) continue;
		break;
	}
	
	addModel(store, numberOfInsert);

	system("cls");
}
