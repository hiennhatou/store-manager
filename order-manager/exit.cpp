#include<iostream>
#include<fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

#include "struct.h";

json modelsParsing(Model* model, unsigned int size) {
	json arrayString;
	if (size == 0) {
		arrayString = json::array();
		return arrayString;
	}
	for (int i = 0; i < size; i++) {
		arrayString.push_back({ {"id", model[i].id}, {"name", model[i].name}, {"price", model[i].price}, {"quantity", model[i].quantity} });
	}
	return arrayString;
}

void deallocation(Store* store) {
	delete[] store->MAC_PRODUCT.models;
	delete[] store->IPHONE_PRODUCT.models;
	delete store;
}

void save(Store* store) {
	json stringify;
	stringify["IPHONE_PRODUCT"]["size"] = store->IPHONE_PRODUCT.size;
	stringify["IPHONE_PRODUCT"]["models"] = modelsParsing(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size);

	stringify["MAC_PRODUCT"]["size"] = store->MAC_PRODUCT.size;
	stringify["MAC_PRODUCT"]["models"] = modelsParsing(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size);

	ofstream file("store.json");
	file << stringify;
	file.close();
}

void exitProcess(Store *store) {
	save(store);
	deallocation(store);
	exit(0);
}
