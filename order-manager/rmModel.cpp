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

	cout << "Nhap ma model can xoa: ";
	getline(cin, b);

	position = ArrayHandler::find(models, size, [b](Model model) {
		return model.id == b;
	});
	
	if (position < 0 || position >= size) return models;
	newModels = ArrayHandler::rm(models, size, position);
	return newModels;
}


void rmModelMenu(Store* store) {
	string a = "";
	while (a != "MAC_PRODUCT" && a != "IPHONE_PRODCT") {
		cout << "Nha ma dong san pham (\"MAC_PRODUCT\" hoac \"IPHONE_PRODCT\"): ";
		getline(cin, a);
	}

	if (a == "MAC_PRODUCT") {
		Model* temp = store->MAC_PRODUCT.models;
		store->MAC_PRODUCT.models = rmModel(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size);
		if (temp != store->MAC_PRODUCT.models) delete[] temp;
		store->MAC_PRODUCT.size -= 1;
	}
	else {
		Model* temp = store->IPHONE_PRODUCT.models;
		store->IPHONE_PRODUCT.models = rmModel(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size);
		if (temp != store->IPHONE_PRODUCT.models) delete[] temp;
		store->IPHONE_PRODUCT.size -= 1;
	}

}