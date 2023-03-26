#include <iostream>
#include <string>
using namespace std;

#include "struct.h"
#include "random.h"
#include "array-handler.h"

Model generateModel() {
	Model model;
	string name;
	unsigned long int price;
	unsigned int quantity;

	cout << "Nhap ten san pham: ";
	getline(cin, name);
	cout << "Nhap gia: ";
	cin >> price;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap so luong: ";
	cin >> quantity;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	model.id = random(10);
	model.name = name;
	model.quantity = quantity;
	model.price = price;
	return model;
}

void addProduct(Store* store) {
	string a;
	while (a != "IPHONE_PRODUCT" && a != "MAC_PRODUCT") {
		cout << "Nhap ma san pham: ";
		cin.clear();
		getline(cin, a);
	}
	cout << "---------\n";
	Model newModel = generateModel();
	
	if (a == "IPHONE_PRODUCT") {
		Model* temp = store->IPHONE_PRODUCT.models;
		store->IPHONE_PRODUCT.models = ArrayHandler::push(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size, newModel);
		delete[] temp;
		store->IPHONE_PRODUCT.size = store->IPHONE_PRODUCT.size + 1;
	}
	else if(a == "MAC_PRODUCT") {
		Model* temp = store->MAC_PRODUCT.models;
		store->MAC_PRODUCT.models = ArrayHandler::push(store->IPHONE_PRODUCT.models, store->MAC_PRODUCT.size, newModel);
		delete[] temp;
		store->MAC_PRODUCT.size = store->MAC_PRODUCT.size + 1;
	}
}

void addProductMenu(Store* store) {
	int numberOfInsert = 0;
	while (numberOfInsert <= 0) {
		cout << "So model can nhap: ";
		cin >> numberOfInsert;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	for (int i = 0; i < numberOfInsert; i++) {
		cout << "========= Them San Pham " << i + 1 << " =========\n";
		addProduct(store);
	}

	system("cls");
}
