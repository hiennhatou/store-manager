#include <iostream>
#include <string>
#include <functional>
using namespace std;

#include "struct.h"
#include "array-handler.h"


Model* rmModel(Model* models, unsigned int size) {
	string b;
	int position;
	Model* newModels;

	for (int i = 0; i < size; i++) {
		cout << "............ Model " << i + 1 << " ............\n";
		cout << "Code: " << models[i].id << endl;
		cout << "Name: " << models[i].name << endl;
	}

	cout << "....................................\n";
	cout << "Nhap ma code cua model can xoa: ";
	getline(cin, b);

	position = ArrayHandler::find(models, size, [b](Model model) {
		return model.id == b;
	});
	
	if (position < 0 || position >= size) {
		cout << "Khong tim thay model\n";
		return models;
	}
	newModels = ArrayHandler::rm(models, size, position);
	return newModels;
}


void rmModelMenu(Store* store) {
	string a = "";
	cout << "Nhap ma code cua dong san pham (\"MAC_PRODUCT\" hoac \"IPHONE_PRODUCT\" hoac nhap bat ky de thoat): ";
	getline(cin, a);
	if (a != "MAC_PRODUCT" && a != "IPHONE_PRODUCT") {
		system("cls");
		return;
	}

	if (a == "MAC_PRODUCT") {
		Model* temp = store->MAC_PRODUCT.models;
		store->MAC_PRODUCT.models = rmModel(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size);
		if (temp != store->MAC_PRODUCT.models) {
			delete[] temp;
			store->MAC_PRODUCT.size -= 1;
		}
	}
	else {
		Model* temp = store->IPHONE_PRODUCT.models;
		store->IPHONE_PRODUCT.models = rmModel(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size);
		if (temp != store->IPHONE_PRODUCT.models) {
			delete[] temp;
			store->IPHONE_PRODUCT.size -= 1;
		}
	}
	system("pause");
	system("cls");

}