#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "struct.h"
#include "json.hpp"
using json = nlohmann::json;

Model* modelsLoading(json jsonData, unsigned int size) {
	unsigned int count = 0;
	Model* model = new Model[size];
	for (json::iterator i = jsonData.begin(); i != jsonData.end(); ++i) {
		model[count].id = (*i)["id"];
		model[count].name = (*i)["name"];
		model[count].price = (*i)["price"];
		model[count].quantity = (*i)["quantity"];
		count++;
	}

	return model;
}

Store* dataLoading() {
	cout << "Loading data........" << endl;
	ifstream initData("store.json");
	json data = json::parse(initData);

	Store* store = new Store;

	store->IPHONE_PRODUCT.size = data["IPHONE_PRODUCT"]["size"];
	Model* iphoneModels = modelsLoading(data["IPHONE_PRODUCT"]["models"], store->IPHONE_PRODUCT.size);
	store->IPHONE_PRODUCT.models = iphoneModels;

	store->MAC_PRODUCT.size = data["MAC_PRODUCT"]["size"];
	Model* macModels = modelsLoading(data["MAC_PRODUCT"]["model"], store->MAC_PRODUCT.size);
	store->MAC_PRODUCT.models = macModels;

	initData.close();

	return store;
}
