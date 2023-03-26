#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "struct.h"
#include "json.hpp"
using json = nlohmann::json;

Model* modelsLoading(json jsonData) {
	unsigned int count = 0;
	json::iterator begin = jsonData.begin();
	json::iterator end = jsonData.end();

	unsigned int size = distance(begin, end);

	Model* model = new Model[size];

	for (json::iterator i = begin; i != end; ++i) {
		model[count].id = ((*i)["id"]);
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

	store->IPHONE_PRODUCT.size = distance(data["IPHONE_PRODUCT"]["models"].begin(), data["IPHONE_PRODUCT"]["models"].end());;
	store->IPHONE_PRODUCT.models = modelsLoading(data["IPHONE_PRODUCT"]["models"]);

	store->MAC_PRODUCT.size = distance(data["MAC_PRODUCT"]["models"].begin(), data["MAC_PRODUCT"]["models"].end());
	store->MAC_PRODUCT.models = modelsLoading(data["MAC_PRODUCT"]["models"]);

	initData.close();
	system("cls");

	return store;
}
