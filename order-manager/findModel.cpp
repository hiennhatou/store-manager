#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

#include "struct.h"

bool advancedComparison(string a, string b) {
	stringstream streamA(a);
	stringstream streamB(b);
	string word;
	while (streamA >> word) {
		if (b.find(word) != string::npos) return true;
		if (word.find(b) != string::npos) return true;
	}
	while (streamB >> word) {
		if (a.find(word) != string::npos) return true;
		if (word.find(a) != string::npos) return true;
	}

	return false;
}

void findModel(Model* models, unsigned int size, string keyword) {
	transform(keyword.begin(), keyword.end(), keyword.begin(), tolower);
	for (unsigned int a = 0; a < size; a++) {
		string name = models[a].name;
		string id = models[a].id;
		transform(name.begin(), name.end(), name.begin(), tolower);
		transform(id.begin(), id.end(), id.begin(), tolower);
		if (
			(id.find(keyword) != string::npos) || 
			(name.find(keyword) != string::npos) ||
			(advancedComparison(name, keyword))
		) {
			cout << "Code: " << models[a].id << endl;
			cout << "Name: " << models[a].name << endl;
			cout << "Price: " << models[a].price << endl;
			cout << "Quantity: " << models[a].quantity << endl;
			cout << "..............................................\n";
		}
	}
}

void findModelMenu(Store* store) {
	string keyword;
	cout << "Nhap keyword can tim kiem: ";
	getline(cin, keyword);
	cout << "----------- MAC PRODUCT LINE -----------\n";
	findModel(store->MAC_PRODUCT.models, store->MAC_PRODUCT.size, keyword);
	cout << "--------- IPHONE PRODUCT LINE ----------\n";
	findModel(store->IPHONE_PRODUCT.models, store->IPHONE_PRODUCT.size, keyword);
	system("pause");
	system("cls");
}
